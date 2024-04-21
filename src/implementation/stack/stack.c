//
// Created by Yoon BeongWook on 4/21/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE
{
    char szData[64];
    struct NODE* next;
} NODE;

NODE* g_pHead = { 0 };

int IsEmpty()
{
    if (g_pHead->next == NULL)
        return 1;
    return 0;
}

// 전체 데이터 출력
void printList(void){
    NODE* pHead = g_pHead;
    while(pHead != NULL){
        printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
        pHead = pHead->next;
    }
}

void ReleaseList(void)
{
    printf("\nReleaseList()\n");
    NODE* pTmp = g_pHead->next;
    while(pTmp != NULL) {
        NODE* pDelete = pTmp;
        pTmp = pTmp -> next;

        printf("Delete: [%p] %s\n", pDelete, pDelete->szData);
        free(pDelete);
    }
    g_pHead->next = 0;
}

int InsertAtHead(char* pszData)
{
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strncpy(pNode-> szData, pszData, sizeof(pNode -> szData));

    if(IsEmpty())
        g_pHead->next = pNode;
    else
    {
        pNode ->next = g_pHead->next;
        g_pHead->next = pNode;
    }
    return 1;
}

void PushData(char* pszData)
{
    InsertAtHead(pszData);
}

int PopData(NODE* pPopNode)
{
    NODE* stack_pointer = g_pHead->next;
    if(IsEmpty())
        return 0;
    memcpy(pPopNode, stack_pointer, sizeof(NODE));
    return 1;
}


int Stack(){
    return 0;
}