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

    while(g_pHead != NULL){
        printf("[%p] %s, next[%p]", g_pHead, g_pHead -> szData, g_pHead -> next);
        g_pHead = g_pHead -> next;
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

    return 0;
}