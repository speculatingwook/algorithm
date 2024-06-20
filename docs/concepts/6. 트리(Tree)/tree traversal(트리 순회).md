- 대표적인 3가지 트리 순회법
	- 전위(pre-order) 순회
	- 중위(in-order) 순회
	- 후위(post-order) 순회
- 하위 트리와 비교했을 때 현재 노드의 방문 순서
	- 중위: 왼쪽 하위 트리 -> 현재 노드 -> 오른쪽 하위 트리
	- 전위: 현재 노드 -> 왼쪽 하위 트리 -> 오른쪽 하위 트리
	- 후위: 왼쪽 하위 트리 -> 오른쪽 하위 트리 -> 현재 노드


### 중위 순회 코드
```java
public static void traverseInOrder(Node node) {
	if(node == null) {
		return;
	}
	
	traverseInOrder(node.left);
	System.out.println(node.data);
	traverseInOrder(node.right);
}
```

```cpp
void traverseInOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    
    traverseInOrder(node->left);
    std::cout << node->data << " ";
    traverseInOrder(node->right);
}
```

## 전위 순회
- 루트 노드부터 시작
- 다음 단계를 재귀적으로 실행
	- 내 노드를 먼저 나열
	- 왼쪽 하위 트리의 노드를 나열
	- 오른쪽 하위 트리의 노드를 나열

### 전위 순회의 용도 1 - 트리 복사
- 부모가 있어야 자식도 추가할 수 있음
- 따라서 전위 순회가 적합
	- 부모를 먼저 나열
	- 다른 순회는 부모가 중간 혹은 마지막
- 물론 다른 순회로도 복사는 가능
	- 직관적이지 않을 뿐

### 전위 순회의 용도 2 - 수식의 전위 표기법
![|209](https://i.imgur.com/BA07Oa5.png)

- 수식은 보통 중위 표기법(infix notation)을 사용
	- 괄호로 우선 순위를 정해줄 수 있음
	- 위 트리를 중위 순회하면 다음 수식이 나옴
		$A * (B-C) - (D + E)$

- 전위 표기법(prefix notation)
	- 폴란드 표기법(Polish notation)이라고도 불림
	- 연산자/괄호의 우선 순위가 없음 (읽는 순서대로 !)
	- 따라서 컴퓨터로 계산하기 좀 더 편함
		$-*A -BC + DE$

### 전위 순회 코드

#### 재귀
```java
public static void traversePreOrder(Node node) {
    if(node == null) {
        return;
    }
    
    System.out.println(node.data);
    traversePreOrder(node.left);
    traversePreOrder(node.right);
}
```

```cpp
void traversePreOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    
    std::cout << node->data << " ";
    traversePreOrder(node->left);
    traversePreOrder(node->right);
}
```

#### 재귀 x
```java
import java.util.Stack;

public static void traversePreOrderIterative(Node root) {
    if (root == null) {
        return;
    }

    Stack<Node> nodes = new Stack<>();
    nodes.push(root);

    while (!nodes.isEmpty()) {
        Node node = nodes.pop();
        System.out.print(node.data + " ");

        if (node.right != null) {
            nodes.push(node.right);
        }

        if (node.left != null) {
            nodes.push(node.left);
        }
    }
}
```

```cpp
#include <stack>
#include <iostream>

void traversePreOrderIterative(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::stack<Node*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        Node* node = nodes.top();
        nodes.pop();
        std::cout << node->data << " ";

        if (node->right) {
            nodes.push(node->right);
        }

        if (node->left) {
            nodes.push(node->left);
        }
    }
}
```

## 후위 순회
- 후위 표기법(postfix notation)
	- 역 폴란드 표기법(reverse Polish notation)
	$ABC -* DE +-$


### 후위 순회 코드
```java
public static void traversePostOrder(Node node) {
    if(node == null) {
        return;
    }
    
    traversePostOrder(node.left);
    traversePostOrder(node.right);
    System.out.println(node.data);
}
```

```cpp
void traversePostOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    
    traversePostOrder(node->left);
    traversePostOrder(node->right);
    std::cout << node->data << " ";
}
```

## 전위/중위/후위 순회
- 앞에서 본 예 외에도 알고리즘에 따라 셋중 하나를 사용
- 간단한  가이드
	- 리프보다 루트를 먼저 봐야 한다면 전위 순회
	- 리프를 다 본 다음 다른 노드를 봐야 한다면 후위 순회
	- 순서대로 봐야 한다면 중위 순회
