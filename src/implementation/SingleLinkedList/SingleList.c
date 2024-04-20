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
}

void ReleaseList(void)
{
    NODE *pTmp = g_pHead;
    while(pTmp != NULL) {
        NODE* pDelete = pTmp;
        pTmp = pTmp -> next;

        printf("Delete: [%p] %s\n", pDelete, pDelete->szData);
        free(pDelete);
    }
}

// 데이터 조회
int FindData(char* pszData)
{
    NODE* pTmp = g_pHead;
    NODE* pPrev = NULL;
    while(pTmp != NULL)
    {
        if(strcmp(pTmp -> szData, pszData) == 0)
        {
            //삭제
            printf("DeleteData(): %s\n", pTmp->szData);
            if(pPrev != NULL)
                pPrev-> next = pTmp -> next;
            else
            {
                // 삭제할 데이터가 첫번째
                g_pHead = pTmp -> next;
                free(pTmp);
            }
            return 1;
        }
        pPrev = pTmp;
        pTmp = pTmp -> next;
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