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

NODE* stack_head = { 0 };

int IsStackEmpty()
{
    if (stack_head->next == NULL)
        return 1;
    return 0;
}

// 전체 데이터 출력
void printStackList(void){
    NODE* pHead = stack_head;
    while(pHead != NULL){
        printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
        pHead = pHead->next;
    }
}
//
//void ReleaseList(void)
//{
//    printf("\nReleaseList()\n");
//    NODE* pTmp = g_pHead->next;
//    while(pTmp != NULL) {
//        NODE* pDelete = pTmp;
//        pTmp = pTmp -> next;
//
//        printf("Delete: [%p] %s\n", pDelete, pDelete->szData);
//        free(pDelete);
//    }
//    g_pHead->next = 0;
//}

int PushData(char* pszData)
{
    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    strncpy(pNode-> szData, pszData, sizeof(pNode -> szData));

    if(IsStackEmpty() == 1)
        stack_head->next = pNode;
    else
    {
        pNode ->next = stack_head->next;
        stack_head->next = pNode;
    }
    return 1;
}

int PopData(NODE* pPopNode)
{
    NODE* stack_pointer = stack_head->next;
    if(IsStackEmpty())
        return 0;
    memcpy(pPopNode, stack_pointer, sizeof(NODE));

    stack_head->next = stack_pointer->next;
    free(stack_pointer);
    return 1;
}


int Stack(){
    printf("stack");
    //Stack 테스트를 위한 코드
//    PushData("TEST01");
//    PushData("TEST02");
//    PushData("TEST03");
    NODE node = {0};
    PopData(&node);
    printf("Pop: %s\n", node.szData);

    PopData(&node);
    printf("Pop: %s\n", node.szData);

    PopData(&node);
    printf("Pop: %s\n", node.szData);
    return 0;
}