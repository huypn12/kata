#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *createTreeNode(int val) {
  struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  newNode->val = val;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

void deleteTreeNode(struct TreeNode *root) {
  if (root->left == NULL && root->right == NULL) {
    free(root);
  } else {
    deleteTreeNode(root->left);
    deleteTreeNode(root->right);
  }
}

struct TreeProps {
  int height;
  int diameter;
};

static inline int max(int argc, ...) {
  int i;
  int max, a;

  va_list argv;
  va_start(argv, argc);
  max = va_arg(argv, int);

  for (i = 2; i <= argc; i++)
    if ((a = va_arg(argv, int)) > max)
      max = a;
  va_end(argv);

  return max;
}

struct TreeProps _diameter(struct TreeNode *node) {
  struct TreeProps p = {0, 0};
  if (node == NULL) return p;

  struct TreeProps lb = _diameter(node->left);
  struct TreeProps rb = _diameter(node->right);

  int rootHeight = 1 + max(2, lb.height, rb.height);
  int rootDiameter = lb.height + rb.height;

  p.height = rootHeight;
  p.diameter = max(3, rootDiameter, lb.diameter, rb.diameter);
  return p;
}

int diameterOfBinaryTree(struct TreeNode *root) {
  struct TreeProps p = _diameter(root);
  return p.diameter;
}

struct TreeNode *createTestTree_1() {
  struct TreeNode *root = createTreeNode(1);
  struct TreeNode *it = root;
  struct TreeNode *newNode = createTreeNode(2);
  root->left = newNode;
  newNode = createTreeNode(3);
  root->right = newNode;
  it = it->left;
  newNode = createTreeNode(4);
  it->left = newNode;
  newNode = createTreeNode(5);
  it->right = newNode;

  return root;
}

struct TreeNode *createTestTree_2() {
  struct TreeNode *root = createTreeNode(1);
  struct TreeNode *it = root;
  struct TreeNode *newNode = createTreeNode(2);
  root->left = newNode;

  return root;
}

int main() {
  struct TreeNode *root = createTestTree_1();
  printf("%d \n", diameterOfBinaryTree(root));
  deleteTreeNode(root);

  root = createTestTree_2();
  printf("%d \n", diameterOfBinaryTree(root));
  //deleteTreeNode(root);
}
