## 이진 트리
- 자식이 최대 둘
	- 왼쪽/오른쪽 자식
- 무언가 계층적(재귀적)으로 이분해 나갈 때 적합

## 이진 트리 -> 이진 탐색 트리
- 자식이 최대 둘
	- 왼쪽/오른쪽 자식
- 무언가 계층적(재귀적)으로 이분해 나갈 때 적합
- 그 무언가를 이분하는 기준을 만든다면?
	- 그 기준에 따라 특화된 이진 트리를 만들 수 있음
	- 그에 따라 보다 효율적인 알고리즘 고안 가능
	- 한 가지 예인 이진 탐색 트리(binary search tree, BST)

## BST
![|350](https://i.imgur.com/xyNHMiu.png)

- 이진 트리에 이분하는 규칙을 추가
	- 왼쪽 자식은 언제나 부모보다 작다
	- 오른쪽 자식은 언제나 부모 이상

- 정렬된 트리
	- 재귀적으로 읽는 순서만 지키면 맞다.

### 순서대로 BST 읽기
![|400](https://i.imgur.com/zmptpwG.png)

- 루트 노드부터 시작
- 다음 단계를 재귀적으로 실행
	- 왼쪽 하위 트리의 노드를 나열
	- 내 노드를 나열
	- 오른쪽 하위 트리의 노드를 나열
	- (중위 순회법 - in order traversal)

## 정렬된 트리 vs 이진 탐색 트리

| 정렬된 배열 | 이진 탐색 트리 |
|-------------|-----------------|
| • 보통 이진 탐색 전에 정렬을 합 | • 탐색 전에 따로 정렬 불필요 |
| ▸ 삽입/삭제 할 때마다 정렬할 수도 있음 | • 데이터 추가 시 정렬된 위치에 추가 |
| • 새로 추가된 데이터는 비정렬 상태 | • 탐색 시간: O(logn) |
| • (일단 정렬 후) 탐색 시간: O(logn) | • 평균 삽입/삭제 시간: O(logn) |
| • 삽입 및 삭제: O(n) | • 연결 리스트 이상 복잡한 데이터 구조 |
| • 매우 간단한 데이터 구조 | • 보통 여러 메모리 덩어리 |
| • 메모리 한 덩어리 | |

## BST의 복잡도

| 자료구조     | 평균      |         |         | 최악   |      |      |
| -------- | ------- | ------- | ------- | ---- | ---- | ---- |
|          | 검색      | 삽입      | 삭제      | 검색   | 삽입   | 삭제   |
| 이진 탐색 트리 | O(logn) | O(logn) | O(logn) | O(n) | O(n) | O(n) |
| 배열       | O(n)    | O(n)    | O(n)    | O(n) | O(n) | O(n) |
| 연결 리스트   | O(n)    | O(1)    | O(1)    | O(n) | O(1) | O(1) |
| 해시 테이블   | O(1)    | O(1)    | O(1)    | O(n) | O(n) | O(n) |
- 공간복잡도는 O(n)

## BST의 탐색
- 기본적으로 이진 탐색과 동일
	- 분할 정복(재귀적)
- 차이점
	- 각 노드마다 두 하위 트리로 이분됨
- 하위 트리로 내려갈 때마다
	- 검색 공간이 절반씩 줄어듦
	- O(log n) -> 평균
- 최악: O(n)
	- 사실상 연결리스트


### code
```java
public static Node getNodeOrNull(Node node, int data){
	if ( node == null) {
		return null;
	}

	if (node.data == data) {
		return node;
	}

	if (data < node.data) {
		return getNodeOrNull(node.left, data);
	}

	return getNodeOrNull(node.right, data);
}
```

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* getNodeOrNull(Node* node, int data) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->data == data) {
        return node;
    }
    if (data < node->data) {
        return getNodeOrNull(node->left, data);
    }
    return getNodeOrNull(node->right, data);
}
```

## BST 삽입 정리
![|275](https://i.imgur.com/MYirZNz.png)

1. 새로운 노드를 받아줄 수 있는 부모 노드를 찾음
	- 트리를 내려가는 방법은 탐색과 같음
	- 새로운 노드를 받아줄 수 있는 부모란?
		- 오른쪽 하위 트리로 내려가야 하는데 오른쪽 자식이 없는 부모
		- 왼쪽 하위 트리로 내려가야 하는데 왼쪽 자식이 없는 부모
2. 그 후, 거기에 자식으로 추가

### code
```java
public class Node {
	private final int data;
	private Node left;
	private Node right;

	public Node(final int data) {
		this.data = data;
	}

	public Node 
	

}
```