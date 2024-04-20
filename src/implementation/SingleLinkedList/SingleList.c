//
// Created by Yoon BeongWook on 4/19/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE
{
    char szData[64];
    struct NODE* next;
} NODE;

NODE* g_pHead = NULL;

// 연결 리스트 전체 데이터 출력
void printList(void){
    NODE* pHead = g_pHead;
    while(pHead != NULL){
        printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
        pHead = pHead->next;
    }
}

int InsertNewNode(char* pszData)
{
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strcpy(pNode-> szData, pszData);

    if(g_pHead == NULL)
        g_pHead = pNode;
    else {
        pNode -> next = g_pHead;
    }

    return 1;
}

int SingleList(){
    // List 테스트를 위한 코드
    InsertNewNode("TEST01");
    InsertNewNode("TEST02");
    InsertNewNode("TEST03");
    printList();
    return 0;
}