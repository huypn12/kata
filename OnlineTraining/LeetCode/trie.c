#include "stdafx.h"

struct TrieNode {
  int key;
  struct TrieNode *next;
  struct TrieNode *child;
};

typedef struct {
  struct TrieNode *head;
} Trie;

/** Initialize your data structure here. */

Trie *trieCreate() {
  Trie *new_trie = (Trie *)malloc(sizeof(Trie));
  assert(new_trie != NULL);

  new_trie->head = NULL;

  return new_trie;
}

struct TrieNode *CreateTreeNode(int key) {
  struct TrieNode *new_trie_node =
      (struct TrieNode *) malloc(sizeof(struct TrieNode));
  assert(new_trie_node != NULL);

  new_trie_node->key = key;
  new_trie_node->child = NULL;
  new_trie_node->next = NULL;

  return new_trie_node;
}

ssize_t __StrLen(char *s)
{
  ssize_t len = 0;
  char *it = s;
  while (*it != '\0') {
    len++;
    it++;
  }
  return len;
}

/** Inserts a word into the trie. */
void trieInsert(Trie *obj, char *word) {
  int w_len = __StrLen(word);
  struct TrieNode *itr = obj->head;
  for (int i = 0; i < w_len + 1; i++) {
    if (itr == NULL) {
      struct TrieNode *new_trie_node = CreateTreeNode(word[i]);
      obj->head = new_trie_node;
      continue;
    }
    struct TrieNode *citr = itr->child;
    while (citr != NULL) {
      if (citr->key == word[i]) {
        itr = citr;
        break;
      }
      citr = citr->next;
    }
    if (citr == NULL) {
      struct TrieNode *new_trie_node = CreateTreeNode(word[i]);
      struct TrieNode *tmp = itr->child;
      itr->child = new_trie_node;
      itr->child->next = tmp;
      itr = itr->child;
    }
  }
}

/** Returns if there is any word in the trie that starts with the given prefix.
 */
bool trieStartsWith(Trie *obj, char *prefix) {
  char *c = prefix;
  struct TrieNode *itr = obj->head;
  if (itr == NULL) {
    return false;
  }
  while (*c != '\0') {
    struct TrieNode *citr = itr->child;
    while (citr != NULL) {
      if (citr->key == *c) {
        itr = citr;
        break;
      }
      citr = citr->next;
    }
    if (citr == NULL) {
      return false;
    }
    c++;
  }
  return true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie *obj, char *word) {
  struct TrieNode *itr = obj->head;
  if (itr == NULL) {
    return false;
  }
  char *c = word;
  for (int i = 0; i < __StrLen(word) + 1; i++) {
    struct TrieNode *citr = itr->child;
    while (citr != NULL) {
      if (citr->key == word[i]) {
        itr = citr;
        break;
      }
      citr = citr->next;
    }
    if (citr == NULL) {
      return false;
    }
  }
  return true;
}

void trieFreeChilds(Trie *obj, struct TrieNode *node) {
  struct TrieNode *c = node->child;
  while (c != NULL) {
    if (c->child != NULL) {
      trieFreeChilds(obj, c->child);
    }
    struct TrieNode *tmp = c;
    c = c->next;
    free(tmp);
  }
}

void trieFree(Trie *obj) {
  trieFreeChilds(obj, obj->head);
  free(obj->head);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);

 * bool param_2 = trieSearch(obj, word);

 * bool param_3 = trieStartsWith(obj, prefix);

 * trieFree(obj);
*/

void Test_1() {
  Trie *obj = trieCreate();
  trieInsert(obj, "abc");
  trieInsert(obj, "apple");
  int res = trieSearch(obj, "apple");   // returns true
  printf("%d\n", res);
  res = trieSearch(obj, "app"); // returns false
  printf("%d\n", res);
  res = trieStartsWith(obj, "app"); // returns true
  printf("%d\n", res);
  trieInsert(obj, "app");
  res = trieSearch(obj, "app");  //return true
  printf("%d\n", res);
  res = trieStartsWith(obj, "app"); // return true
  printf("%d\n", res);
  res = trieStartsWith(obj, "ap"); // return true
  printf("%d\n", res);
  res = trieSearch(obj, "ap"); // return false
  printf("%d\n", res);
  trieFree(obj);
}

int main() {
  Test_1();

  return 0;
}
