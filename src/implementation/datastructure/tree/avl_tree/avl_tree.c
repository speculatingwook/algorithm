//
// Created by Yoon BeongWook on 5/20/24.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* rotateRight(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));
    newRoot->height = 1 + (getHeight(newRoot->left) > getHeight(newRoot->right) ? getHeight(newRoot->left) : getHeight(newRoot->right));

    return newRoot;
}

Node* rotateLeft(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));
    newRoot->height = 1 + (getHeight(newRoot->left) > getHeight(newRoot->right) ? getHeight(newRoot->left) : getHeight(newRoot->right));

    return newRoot;
}

Node* insertHelper(Node* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insertHelper(node->left, key);
    else if (key > node->key)
        node->right = insertHelper(node->right, key);
    else
        return node; // 중복 키는 허용하지 않음

    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    int balanceFactor = getBalanceFactor(node);

    // LL 케이스
    if (balanceFactor > 1 && key < node->left->key)
        return rotateRight(node);

    // RR 케이스
    if (balanceFactor < -1 && key > node->right->key)
        return rotateLeft(node);

    // LR 케이스
    if (balanceFactor > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RL 케이스
    if (balanceFactor < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void inorderTraversalHelper(Node* node) {
    if (node != NULL) {
        inorderTraversalHelper(node->left);
        printf("%d ", node->key);
        inorderTraversalHelper(node->right);
    }
}

Node* insert(Node* root, int key) {
    return insertHelper(root, key);
}

void inorderTraversal(Node* root) {
    inorderTraversalHelper(root);
    printf("\n");
}

int avl_tree_test() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("중위 순회 결과: ");
    inorderTraversal(root);

    return 0;
}