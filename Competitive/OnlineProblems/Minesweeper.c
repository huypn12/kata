#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
  ==============================================================================
  Minesweeper application logic interface
  ==============================================================================
*/
enum app_signal {
  MNSWP_NEW_GAME = 1,
  MNSWP_SHOW_MINEFIELD,
  MNSWP_CLICK,
  MNSWP_INDICATE,
  MNSWP_HELP,
  MNSWP_EXIT,
  MNSWP_INVALID,
  MNSWP_VALID,
  MNSWP_WIN,
  MNSWP_LOSE,
  MNSWP_NOOP
};

void clear_input_buffer();
void wait_return();
int display_main_menu();
int input_coordinate(int *prow, int *pcol);
void show_help();
int app();

/*
  ==============================================================================
  Minesweeper core logic interface
  ==============================================================================
*/
#define MINEFIELD_SIZE 10
#define MAX_MINES_COUNT 15

int g_minefield[MINEFIELD_SIZE][MINEFIELD_SIZE];

enum cell_state {
  CELL_KABOOM = -5,
  CELL_MARKED_MINE,
  CELL_HIDDEN_MINE,
  CELL_INDICATED,
  CELL_UNREVEALED,
  CELL_EMPTY
};

void init_minefield();
int setup_minefield();
void show_minefield();
int click(int row, int col);
int indicate(int row, int col);

/*
  ==============================================================================
  Minesweeper application logic implementation
  ==============================================================================
*/
void init_minefield()
{
  int i, j;
  for (i = 0; i < MINEFIELD_SIZE; ++i) {
    for (j = 0; j < MINEFIELD_SIZE; ++j) {
      g_minefield[i][j] = CELL_UNREVEALED;
    }
  }
}

int gen_random_int(int min, int max)
{
  int result = rand() % (max + 1 - min) + min;
  return result;
}

void gen_random_pair(int *row, int *col)
{
  *row = gen_random_int(0, MINEFIELD_SIZE);
  *col = gen_random_int(0, MINEFIELD_SIZE);
}

int setup_minefield()
{
  int mines_count = gen_random_int(1, MAX_MINES_COUNT);
  int mine_i;
  for (mine_i = 0; mine_i < mines_count; ++mine_i) {
    int mine_row, mine_col;
    gen_random_pair(&mine_row, &mine_col);
    g_minefield[mine_row][mine_col] = CELL_HIDDEN_MINE;
  }
  return mines_count;
}

int is_valid_coordinate(int row, int col)
{
  if (row < 0 || row >= MINEFIELD_SIZE
      || col < 0 || col >= MINEFIELD_SIZE)
    return 0;
  return 1;
}

int has_mine_adjacent(int row, int col)
{
  int mines_count = 0;
  int i, j;
  for (i = -1; i <= 1; ++i) {
    for (j = -1; j <= 1; ++j) {
      int adj_row = row + i;
      int adj_col = col + j;
      if (!is_valid_coordinate(adj_row, adj_col)) {
        continue;
      }

      if (g_minefield[adj_row][adj_col] == CELL_HIDDEN_MINE) {
        ++mines_count;
      }
    }
  }

  return mines_count;
}

void flood_adjacent_cells(int row, int col)
{
  /* two cells are adjacent if and only if:
     they are in the same vertical, or horizontal, or diagonal line */

  /* Stack initialization*/
  int stack_size = MAX_MINES_COUNT * MAX_MINES_COUNT;
  int stack_row[stack_size];
  int stack_col[stack_size];

  /* Push first cell to stack*/
  int stack_top = 0;
  stack_row[stack_top] = row;
  stack_col[stack_top] = col;

  while (stack_top >= 0) {
    /* Pop Top*/
    int center_row = stack_row[stack_top];
    int center_col = stack_col[stack_top];
    stack_top -= 1;

    int adj_mines_count = has_mine_adjacent(center_row, center_col);
    if (adj_mines_count > 0) {
      g_minefield[center_row][center_col] = adj_mines_count;
      continue;
    }
    g_minefield[center_row][center_col] = CELL_EMPTY;

    /* Check status of all adjacent*/
    int i, j;
    for (i = -1; i <= 1; ++i) {
      for (j = -1; j <= 1; ++j) {
        int adj_row = center_row + i;
        int adj_col = center_col + j;

        if (!is_valid_coordinate(adj_row, adj_col)) { continue; }
        if (g_minefield[adj_row][adj_col] != CELL_UNREVEALED) { continue; }

        stack_top += 1;
        stack_row[stack_top] = adj_row;
        stack_col[stack_top] = adj_col;
      }
    }
  }
}

int click(int row, int col)
{
  int cell_state = g_minefield[row][col];
  if (cell_state == CELL_HIDDEN_MINE) {
    g_minefield[row][col] = CELL_KABOOM;
    return MNSWP_LOSE;
  } else if (cell_state == CELL_INDICATED || cell_state == CELL_MARKED_MINE) {
    return MNSWP_NOOP;
  } else if (cell_state == CELL_UNREVEALED) {
    flood_adjacent_cells(row, col);
  } else {
    return MNSWP_NOOP;
  }
}

int indicate(int row, int col)
{
  /* Return number of correctly indicated mine*/
  int cell_state = g_minefield[row][col];
  /* Indicating normal cell */
  if (cell_state == CELL_INDICATED) {
    g_minefield[row][col] = CELL_UNREVEALED;
    return 0;
  } else if (cell_state == CELL_UNREVEALED) {
    g_minefield[row][col] = CELL_INDICATED;
    return 0;
  }
  /* Indicating cell with hidden mine*/
  else if (cell_state == CELL_HIDDEN_MINE) {
    g_minefield[row][col] = CELL_MARKED_MINE;
    return 1;
  } else if (cell_state == CELL_MARKED_MINE) {
    g_minefield[row][col] = CELL_HIDDEN_MINE;
    return -1;
  }
}


void show_minefield()
{
  /* Column axis*/
  printf("\t     %02d %02d %02d %02d %02d %02d %02d %02d %02d %02d\n",
         1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  printf("\t    ------------------------------\n");

  int i,j;
  for (i = 0; i < MINEFIELD_SIZE; ++i) {
    /* Row axis*/
    printf("\t%02d | ", i + 1);

    for (j = 0; j < MINEFIELD_SIZE; ++j) {
      int cell_value = g_minefield[i][j];
      if (cell_value == CELL_UNREVEALED || cell_value == CELL_HIDDEN_MINE) {
        printf(" . ");
      } else if (cell_value == CELL_INDICATED || cell_value == CELL_MARKED_MINE) {
        printf(" # ");
      } else if (cell_value == CELL_EMPTY) {
        printf("   ");
      } else if (cell_value == CELL_KABOOM) {
        printf(" * ");
      } else {
        printf("%02d ", cell_value);
      }
    }
    printf("\n");
  }
}

/*
  ==============================================================================
  Minesweeper application logic implementation
  ==============================================================================
*/

void clear_input_buffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
}

void wait_return()
{
  printf("Press any key to start a new game...");
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
}

int display_main_menu()
{
  printf("\nSelect option:\n");
  printf("1. New game\n");
  printf("2. Show minefield\n");
  printf("3. Click\n");
  printf("4. Indicate\n");
  printf("5. Help\n");
  printf("6. Exit\n");
  printf("[Your selection]: ");

  int selection = 0;
  scanf("%d", &selection);
  if (selection < MNSWP_NEW_GAME || selection > MNSWP_EXIT) {
    clear_input_buffer();
    return MNSWP_INVALID;
  }

  return selection;
}


int input_coordinate(int *prow, int *pcol)
{
  int row = -1, col = -1;
  printf("§ Enter the cell coordinates row and column: ");
  scanf("%d %d", &row, &col);
  if (!is_valid_coordinate(row - 1, row - 1)) {
    clear_input_buffer();
    return MNSWP_INVALID;
  }
  /* Subtract 1 since the example has index from 1 */
  *prow = row - 1;
  *pcol = col - 1;

  return MNSWP_VALID;
}

void show_help()
{
  printf("1. Press 1 to start a new game. Board is reset, all steps will be discarded.");
  printf("2. Press 2 to print current minefield.\n");
  printf("3. Press 3 to click on a cell\n");
  printf("\t >>> Input format: row col \n\t >>> where x and y are the coordinates of a cell (in range 1..10)\n");
  printf("4. Press 4 to indicate a cell\n");
  printf("\t >>> Input format: row col \n\t >>> where x and y are the coordinates of a cell (in range 1..10)\n");
  printf("5. Press 5 to print help info\n");
  printf("6. Press 6 to get rid of this shit\n");
}

int app()
{
  time_t rand_seed;
  srand((unsigned) time(&rand_seed));

  int signal = MNSWP_NEW_GAME;

  int mines_count = 0;
  while (signal != MNSWP_EXIT) {
    signal = display_main_menu();
    if (signal == MNSWP_NEW_GAME) {
      init_minefield();
      mines_count = setup_minefield();
      printf("\t Created a new game\n");
      show_minefield();
    } else if (signal == MNSWP_SHOW_MINEFIELD) {
      printf("\t Current mine field\n");
      show_minefield();
    } else if (signal == MNSWP_CLICK || signal == MNSWP_INDICATE) {
      /* Input coordinate */
      int row, col;
      int valid = input_coordinate(&row, &col);
      if (valid == MNSWP_INVALID) {
        printf("\t § +++Invalid input format+++");
      }
      /* Handle click */
      int result;
      if (signal == MNSWP_CLICK) {
        result = click(row, col);
        if (result == MNSWP_WIN) {
          printf("\n\t YOU HAVE WON THE GAME. \n ");
          show_minefield();
          wait_return();
          signal = MNSWP_NEW_GAME;
        } else if (result == MNSWP_LOSE) {
          printf("\n\t Good luck next time. \n");
          show_minefield();
          wait_return();
          signal = MNSWP_NEW_GAME;
        } else {
          show_minefield();
        }
      } else {
        /* Handle Indicate */
        result = indicate(row, col);
        mines_count -= result;
        if (mines_count == 0) {
          printf("\n\t YOU HAVE WON THE GAME. \n ");
          show_minefield();
          wait_return();
          signal = MNSWP_NEW_GAME;
        }
      }
    } else if (signal == MNSWP_HELP) {
      show_help();
    } else if (signal == MNSWP_EXIT) {
      printf("Bye bye.\n");
      continue;
    } else {
      printf("§ +++Invalid selection+++\n");
      continue;
    }
  }

}


/*
  ==============================================================================
  Main application
  ==============================================================================
*/

int main()
{
  app();
  return EXIT_SUCCESS;
}
