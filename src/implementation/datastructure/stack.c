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

NODE* stack_head = NULL;

int IsStackEmpty() {
    return (stack_head == NULL || stack_head->next == NULL);
}

void printStackList(void) {
    NODE* pHead = stack_head->next;
    while (pHead != NULL) {
        printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
        pHead = pHead->next;
    }
}

void ReleaseStackList(void) {
    NODE* pTmp = stack_head->next;
    while (pTmp != NULL) {
        NODE* pDelete = pTmp;
        pTmp = pTmp->next;
        printf("Delete: [%p] %s\n", pDelete, pDelete->szData);
        free(pDelete);
    }
    free(stack_head);
    stack_head = NULL;
}

int PushData(char* pszData) {
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strncpy(pNode->szData, pszData, sizeof(pNode->szData));

    if (stack_head == NULL) {
        stack_head = (NODE*)malloc(sizeof(NODE));
        memset(stack_head, 0, sizeof(NODE));
        stack_head->next = pNode;
    } else {
        pNode->next = stack_head->next;
        stack_head->next = pNode;
    }
    return 1;
}

int PopData(NODE* pPopNode) {
    if (IsStackEmpty())
        return 0;

    NODE* stack_pointer = stack_head->next;
    memcpy(pPopNode, stack_pointer, sizeof(NODE));
    stack_head->next = stack_pointer->next;
    free(stack_pointer);
    return 1;
}

int Stack() {
    printf("stack\n");
    PushData("TEST01");
    PushData("TEST02");
    PushData("TEST03");

    NODE node = {0};
    PopData(&node);
    printf("Pop: %s\n", node.szData);

    PopData(&node);
    printf("Pop: %s\n", node.szData);

    PopData(&node);
    printf("Pop: %s\n", node.szData);

    ReleaseStackList();
    return 0;
}