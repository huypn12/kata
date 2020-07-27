#include "stdafx.h"

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *oddEvenList(struct ListNode *head)
{
    if (head == NULL) {
        return NULL;
    }

    int index = 1;
    struct ListNode *lastOdd = head;
    if (head->next == NULL) {
        return head;
    }

    index = 2;
    struct ListNode *lastEven = head->next;
    struct ListNode *firstEven = lastEven;

    struct ListNode *iter = lastEven->next;
    while (iter != NULL) {
        index++;
        if (index % 2 == 0) {
            lastEven->next = iter;
            lastEven = iter;
        } else {
            lastOdd->next = iter;
            lastOdd = iter;
        }
        iter = iter->next;
    }

    lastOdd->next = firstEven;
    lastEven->next = NULL;

    return head;
}

void printList(struct ListNode *head)
{
    struct ListNode *iter = head;
    while (iter != NULL) {
        printf("%d -> ", iter->val);
        iter = iter->next;
    }
    printf("NULL \n");
}

void test_1()
{
    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));
    head->val = 1;
    struct ListNode *iter = head;
    for (int i = 2; i <= 5; i++) {
        struct ListNode *newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        newNode->val = i;
        iter->next = newNode;
        iter = iter->next;
    }
    iter->next = NULL;
    printList(head);

    oddEvenList(head);
    printList(head);
    printf("\n");
}

void test_2()
{
    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));
    head->val = 1;
    struct ListNode *iter = head;
    for (int i = 2; i <= 7; i++) {
        struct ListNode *newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        newNode->val = i;
        iter->next = newNode;
        iter = iter->next;
    }
    iter->next = NULL;
    int valueMap[7] = {2, 1, 3, 5, 6, 4, 7};
    iter = head;
    int i = 0;
    while (iter != NULL) {
        iter->val = valueMap[i];
        iter = iter->next;
        i++;
    }
    printList(head);

    oddEvenList(head);

    printList(head);
}

void test_3()
{
    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));
    head->val = 1;
    struct ListNode *iter = head;
    printList(head);

    oddEvenList(head);

    printList(head);
}

int main()
{
    test_1();
    test_2();
    test_3();
    return EXIT_SUCCESS;
}