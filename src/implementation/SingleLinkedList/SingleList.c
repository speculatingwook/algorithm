//
// Created by Yoon BeongWook on 4/19/24.
//
#include "stdio.h"

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

int SingleList(){

    return 0;
}