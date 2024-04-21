//
// Created by Yoon BeongWook on 4/21/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE {
    char szData[64];
    struct NODE* next;
} NODE;

NODE* p_head = NULL;

int IsQueueEmpty() {
    return (p_head == NULL || p_head->next == NULL);
}

void printQueueList(void) {
    NODE* pHead = p_head->next;
    while (pHead != NULL) {
        printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
        pHead = pHead->next;
    }
}

void ReleaseQueueList(void) {
    NODE* pTmp = p_head->next;
    while (pTmp != NULL) {
        NODE* pDelete = pTmp;
        pTmp = pTmp->next;
        printf("Delete: [%p] %s\n", pDelete, pDelete->szData);
        free(pDelete);
    }
    free(p_head);
    p_head = NULL;
}


int Enqueue(char* pszData)
{
    // 마지막 노드를 찾는다.
    NODE* pTmp = &p_head;
    while (pTmp -> next !=0)
        pTmp = pTmp -> next;

    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strncpy(pNode->szData, pszData, sizeof(pNode->szData));

    pTmp->next = pNode;
    return 1;
}

int Dequeue(NODE* pGetNode) {
    if (IsQueueEmpty())
        return 0;

    NODE* stack_pointer = p_head->next;
    memcpy(pGetNode, stack_pointer, sizeof(NODE));
    p_head->next = stack_pointer->next;
    free(stack_pointer);
    return 1;
}

int Queue() {
    // Queue 테스트를 위한 코드

    Enqueue("TEST01");
    Enqueue("TEST02");
    Enqueue("TEST03");

    printQueueList();

    NODE node = {0};
    Dequeue(&node);
    printf("Dequeue: %s\n", node.szData);

    Dequeue(&node);
    printf("Dequeue: %s\n", node.szData);

    Dequeue(&node);
    printf("Dequeue: %s\n", node.szData);

    ReleaseQueueList();
    return 0;
}