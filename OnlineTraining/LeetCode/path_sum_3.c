#include "stdafx.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// DFS
#define MAX_SIZE 1000
struct TreeNode stack_nodes[MAX_SIZE];
int q_distances[MAX_SIZE];
int q_top = -1;
int parent_node[MAX_SIZE];

int pathSum(struct TreeNode *root, int sum) {
  int path_count = 0;
  stack_top++;
  stack_nodes[stack_top] = root->val;
  while (stack_top >= 0) {
    
  }
  return -1;
}

struct TreeNode *CreateTestTree() {}

void DestroyTestTree()
{
  
}
