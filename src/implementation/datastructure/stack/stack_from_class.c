//
// Created by Yoon BeongWook on 4/24/24.
//

int Stack[N];
int SP;

int init(){
    SP = 0;
    return 0;
}

int isEmpty(){
    return SP==0;
}

int Push(int x){
    Stack[SP++] = x;
    return 0;
}

int Pop(){
    return Stack[--SP];
}