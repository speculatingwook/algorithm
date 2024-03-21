
- 자료구조의 가장 중요한 연산
- 모든 자료구조에 해당하지는 않음
- Item: 저장되는 대상을 부를 이름




## How to Store Items in an Array?

### Packed vs Unpacked
- 배열이 항상 가득 찬 것은 아님
- 빈 자리를 한 쪽으로 모은다?
### Sorted vs Unsorted
- Item들이 정렬된 상태를 유지하느냐 아니냐


## Packed, Unsorted
- 아마도 가장 간단한 방법
- Item의 개수를 표시하는 변수가 따로 필요


### Packed, UnSorted 성능
- Search: $O(N)$
- Insert: (Search, $O(N)$), $O(1)$
- Delete:(Search, $O(N)$), $O(1)$

	- Insert와 Delete는 보통 Search를 먼저 수행


## Packed, Sorted
- Binary Search


### Packed, Sorted 성능

- Search: $O(log N)$
- Insert: (Search, $O(log N)$), $O(N)$
- Delete: (Search, $O(log N)$), $O(N)$



## Unpacked, Unsorted
- 빈 자리들이 흩어져 있음
- Item 별로 사용 중인지 아닌지 표시 필요

### Unpacked, Unsorted 성능
- Search: $O(N)$ -> 기술 추가 -> $O(log N)$
- Insert: (Search, $O(N)$), $O(N)$ -> 기술 추가 -> $(O(1))$
- Delete:(Search, $O(N)$), $O(1)$


## Unpacked, Sorted
- 빈 자리들이 흩어져 있음
- Item 병오 사용 중인지 아닌지 표시 필요

### Unpacked, Sorted 성능
- Search: $O(N)$ -> 기술 추가 -> $O(log N)$
- Insert: (Search, $O(N)$), $O(N)$ -> 기술 추가 -> $(O(1))$
- Delete:(Search, $O(N)$), $O(1)$
