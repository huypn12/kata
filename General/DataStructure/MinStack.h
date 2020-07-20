/*
Design a stack that supports push, pop, top, and retrieving the minimum element
in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  struct StackNode *min;
  struct StackNode *head;
} MinStack;

struct StackNode {
  int val;
  struct StackNode *next;
};

/** initialize your data structure here. */
MinStack *minStackCreate() {
  MinStack *stk = (MinStack *)malloc(sizeof(MinStack));
  stk->min = NULL;
  stk->head = NULL;
  return stk;
}

void minStackPush(MinStack *obj, int x) {
  struct StackNode *newNode =
      (struct StackNode *)malloc(sizeof(struct StackNode));
  newNode->val = x;
  newNode->next = obj->head;

  obj->head = newNode;
  if (obj->min == NULL) {
    obj->min = obj->head;
  } else {
    if (obj->min->val > x) {
      obj->min = obj->head;
    }
  }
}

void updateMin(MinStack *obj) {
  obj->min = obj->head;
  struct StackNode *it = obj->head;
  while (it != NULL) {
    if (it->val < obj->min->val) {
      obj->min = it;
    }
    it = it->next;
  }
};

void minStackPop(MinStack *obj) {
  if (obj->head == NULL) {
    return;
  }
  struct StackNode *rm = obj->head;
  if (obj->min == obj->head) {
    obj->head = obj->head->next;
    updateMin(obj);
  } else {
    obj->head = obj->head->next;
  }
  free(rm);
}

int minStackTop(MinStack *obj) { return obj->head->val; }

int minStackGetMin(MinStack *obj) { return obj->min->val; }

void minStackFree(MinStack *obj) {
  struct StackNode *it = obj->head;
  while (it != NULL) {
    struct StackNode *tmp = it->next;
    free(it);
    it = tmp;
  }
  free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
int main() {

  MinStack *minStack = minStackCreate();
  minStackPush(minStack, -2);
  minStackPush(minStack, 0);
  minStackPush(minStack, -3);
  printf("%d\n", minStackGetMin(minStack));
  minStackPop(minStack);
  printf("%d\n", minStackTop(minStack));
  printf("%d\n", minStackGetMin(minStack));
  minStackFree(minStack);
}