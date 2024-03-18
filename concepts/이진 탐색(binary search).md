
## 작동 방법

1. 가운데 위치를 확인
 ![[binary_search_1.png]]

 2. 가운데 값과 찾으려는 값을 비교
![[binary_search_2.png]]


3. 다시 가운데 위치를 확인
![[binary_search_3.png]]


4. 비교 후 다시 정함
![[binary_search_4.png]]



## 이진 탐색의 시간 복잡도

$O(log n)$ 

- 한 단계 거쳐갈수록 탐색의 범위가 2배씩 줄어듬


## 이진 탐색 알고리즘
- **정렬된 배열**에서 어떤 값의 위치를 찾는 알고리즘
- 한 단계 진행할 때마다 탐색범위를 절반으로 줄임
	- 이진(binary)이라는 이름이 탄생한 이유
- 분할 정복(divide-and-conquer) 알고리즘중 하나
	- 정복이라 하기에는 모든 문제 영역을 방문하지 않음
	- 따라서 decrease-and-conquer라고 부르자는 소수설도 있음
- 재귀함수로 쉽게 작성 가능

```java
binarySearchRecursive(int nums[], int l, int r, int value){
	if(l>r){
		break;
	}
	int m = (l + r) / 2;
	
	
	
}
```


