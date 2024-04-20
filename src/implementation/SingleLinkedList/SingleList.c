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
// 새로운 노드 삽입
int InsertNewNode(char* pszData)
{
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strncpy(pNode-> szData, pszData, sizeof(pNode -> szData));


    if(g_pHead == NULL) // 헤드 노드가 NULL인 경우 = 연결 리스트가 존재하지 않을 경우
        g_pHead = pNode;
    else { // 연결리스트가 존재하는 경우
        // 새로 생성한 노드의 next(가리키는 주소)를 기존의 노드로 설정
        pNode -> next = g_pHead;
        // 새로 생성한 노드를 헤드 노드로 설정
        g_pHead = pNode;
    }

    return 1;
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