//
// Created by Yoon BeongWook on 4/24/24.
//

class Node {
public:
    int data;
    Node *n;
};

class List {
    List();
    ~List();
    int Search(int);
    int Insert(int);

    int Delete(int);

    /*
     * - p,l은 search에서 사용할 포인터
     * - <검색 성공>
     * - l에 검색한 값을 가지는 노드의 주소가 저장
     * - p에는 그 이전 노드의 주소 저장
     * - <검색 실패>
     * - p와 l이 가리키는 노드 사이에 검색값이 삽입되어야 정렬된 상태를 유지하도록 p,l 값 정함
     * */
    Node *head;
    Node *p, *l;
};

List::List() {
    head = nullptr;
}

List::~List(){
    Node *current, *next;
    current = head;
    while(current != nullptr) {
        next = current -> n;
        delete current;
        current = next;
    }
}

int List::Search(int x){
    p = nullptr;
    l = head;
    while (l != nullptr) {
        if(l-> data == x) return 1;
        else if(l->data > x) return 0;
        else{
            p = l; l = l->n;
        }
    }
}

int List::Insert(int x) {
    if(!Search(x)) {
        Node* new_node = new Node;
        new_node -> data = x;
        if(p == nullptr)
            head = new_node;
        else
            p->n = new_node;
        new_node -> n = l;
        return 1;
    }
    return 0;
}

int List::Delete(int x){
    if (Search(x)) {
        if(p == nullptr)
            head = l->n;
        else
            p->n = l-> n;
        delete l;
        return 1;
    }
    return 0;
}