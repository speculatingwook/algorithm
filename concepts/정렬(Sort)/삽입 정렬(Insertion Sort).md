
- 버블 정렬, 선택 정렬보다 구현은 아주 조금 힘듦
- 목록을 차례대로 훑으면서 다음 과정을 반복
	- 현재 위치의 요소를 뽑음
	- 이걸 과거에 방문했던 요소들 중에 어디 사이에 넣어야 정렬이 유지되는지 판단
	- 그 위치에 삽입
	- 삽입으로 인해 다른 요소들을 오른쪽으로 밀어야(shift)할 수도 있음

```java
public static void insertionSort(int[] arr) {
    int n = arr.length;
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
            greater than key, to one position ahead
            of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

```
