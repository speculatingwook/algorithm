//
// Created by Yoon BeongWook on 4/24/24.
//

int Queue[100];
int Head, Tail;

int init(){
    Head = Tail = 0;
}

int isEmpty(){
    return Head == Tail;
}

int insert(int x){
    Queue[Head] = x;
    Head = (Head + 1) % 100;
    return 0;
}

int delete()
{
    int Return_value;
    Return_value = Queue[Tail];
    Tail = (Tail + 1) % 100;
    return Return_value;
}
