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

NODE* g_pHead = { 0 };

int IsEmpty()
{
    if (g_pHead->next == NULL)
        return 1;
    return 0;
}

// 연결 리스트 전체 데이터 출력
void printList(void){
    NODE* pHead = g_pHead;
    while(pHead != NULL){
        printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
        pHead = pHead->next;
    }
}
// 새로운 노드 삽입
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

int InsertAtTail(char* pszData)
{
    // 마지막 노드를 찾는다.
    NODE* pTmp = &g_pHead;
    while (pTmp -> next !=0)
        pTmp = pTmp -> next;

    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strncpy(pNode->szData, pszData, sizeof(pNode->szData));

    pTmp->next = pNode;
    return 1;
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

// 데이터 조회
NODE* FindData(char* pszData)
{
    NODE* pCur = g_pHead->next;
    NODE* pPrev = &g_pHead;
    while(pCur !=NULL)
    {
        if(strcmp(pCur -> szData, pszData) == 0)
            return pPrev;
        pCur = pCur->next;
        pPrev = pPrev->next;
    }

    return 0;
}
// 데이터 삭제
int DeleteData(char* pszData)
{
    NODE* pPrev = FindData(pszData);
    if(pPrev != 0)
    {
        NODE* pDelete = pPrev -> next;
        pPrev->next = pDelete -> next;

        printf("DeleteData(): %s\n", pDelete->szData);
        free(pDelete);
        return 1;
    }
    return 0;
}


int SingleList(){
    // List 테스트를 위한 코드
    InsertNewNode("TEST01");
    InsertNewNode("TEST02");
    InsertNewNode("TEST03");
    printList();
    if(FindData("TEST01") == 1)
        printf("FindData(): TEST01 found\n");
    ReleaseList();
    return 0;
}