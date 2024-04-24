## 자료구조와 배열

### 자료구조의 주요 연산

- 검색(Search), 삽입(Insert), 삭제(Delete)
- 모든 자료구조에 해당하는 것은 아님
- 저장된 대상을 Item이라고 부름

### 배열(Array)

배열은 동일한 데이터 유형의 요소들이 순서대로 저장된 연속적인 메모리 공간

### 배열(Array)에 Item 저장하기

#### Packed vs Unpacked

- 배열이 가득 찬 경우(Packed)와 빈 공간이 있는 경우(Unpacked)
- Unpacked 경우 빈 공간을 한쪽으로 모을 수 있음

#### Sorted vs Unsorted

- Item들이 정렬된 상태(Sorted)인지 아닌지(Unsorted)

#### Packed, Unsorted

- 가장 간단한 방식
- Item의 개수를 별도 변수로 관리

##### 성능

- Search: O(N)
- Insert: Search O(N) 후 O(1)
- Delete: Search O(N) 후 O(1)

#### Packed, Sorted

- Binary Search 가능

##### 성능

- Search: O(log N)
- Insert: Search O(log N) 후 O(N)
- Delete: Search O(log N) 후 O(N)

#### Unpacked, Unsorted

- 빈 공간이 흩어져 있음
- Item별로 사용 중인지 표시 필요

##### 성능

- Search: 일반적으로 O(N), 기술 추가 시 O(log N) 가능
- Insert: Search O(N) 후 O(N), 기술 추가 시 O(1) 가능
- Delete: Search O(N) 후 O(1)

#### Unpacked, Sorted

##### 성능

- Search: 일반적으로 O(N), 기술 추가 시 O(log N) 가능
- Insert: Search O(N) 후 O(N)
- Delete: Search O(N) 후 O(1)

### 배열의 특징

- 연속된 메모리 주소, 동일한 데이터 타입
- 장점: 임의 접근(k번째 Item) 시간 복잡도 O(1), 검색 빠름
- 단점: 크기 변화 시 비용 큼, 삽입/삭제 느릴 수 있음
- 용도: 데이터 변화가 적은 경우 적합

### 배열 검색 알고리즘
## Linear Search

```c
int search(int a[], int n, int x){
   int i;
   for (i=0; i<n; i++)
       if (a[i] == x) return i;
   return -1;
}

int search(int a[], int n, int x){
    int i;
    for(i=0; i<n; i++)
        if(*(a+i) == x) return i;
    return -1;
}
```


## Binary Search

```c
int search(int a[], int n, int x){
    int l, r, m;
    l=0; r = n-1;
    while (l<=r){
        m = (l + r) / 2;
        if (a[m] < x)
            l = m+1;
        else if (a[m] > x)
            r = m-1;
        else
            return m;
    }
    return -1;
}
```


