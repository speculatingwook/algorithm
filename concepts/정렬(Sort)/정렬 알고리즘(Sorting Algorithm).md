면접시, 최소한 코드수준까지 구현할 알고리즘 한개, 과정을 완벽하게 설명할 수 있는 알고리즘 한개는 숙지하고 있어야 한다.

- 목록 안에 저장된 요소들을 특정한 순서대로 재배치하는 알고리즘
- 정렬을 하는 이유
	- 좀 더 효율적으로 알고리즘을 사용하기 위해
	- 사람이 읽기 편하도록
	- 등
- 입력 데이터는 일반적으로 배열 같은 데이터 구조에 저장
	- 아무 위치로의 임의 접근을 허용
	- 연결 리스트를 사용하면 처음 혹은 끝부터 차례대로 훑어야 함

- 흔히 사용하는 순서: 숫자 순서, 사전 순서
- 정렬 방향: 오름차순, 내림차순
- 다양한 정렬 알고리즘이 있음
	- 시간 복잡도 차이
	- 메모리 사용량 차이
	- 안정성(stabilty) 차이
	- 직렬 vs 병렬 차이
		- 이 과목에서는 직렬 정렬 알고리즘만 배움


## 정렬 알고리즘의 안정성
- 안전성(safety)이 아님!
- 똑같은 키(key)를 가진 데이터들의 순서가 바뀌지 않느냐 여부
![](sort_stability_1.png)

## 안정성을 잘 모르는 이유
- 같은 키를 가진 데이터의 순서가 바뀌어도 문제가 아닌 경우가 보통
- 그래서 잘 모르고 생각도 안 하는 부분
- 심지어는 이렇게 잘못 생각하기도 함
	- '모든 정렬 알고리즘은 같은 키를 가진 데이터의 순서를 안 바꾼다'
- 이 때문에 버그가 나도 못 고치는 경우가 있음
- 진실
	- 어떤 정렬 알고리즘은 안정성을 보장
	- 어떤 정렬 알고리즘은 보장 안함

## 안정성이 문제가 되는 경우
1. 정렬의 기준이 되는 정렬 키(sort key)와 실제 데이터가 다름
![](non_stable_sort_problem_1.png)

2. 구조체 / 클래스의 일부 멤버만 정렬 키로 사용
![](non_stable_sort_problem_2.png)

## 대표적인 정렬 알고리즘

### 언제라도 구현할 수 있어야 함
- 버블 정렬
- 선택 정렬



### 여기서부터 알고리즘 속도가 빠름
### 언제라도 설명할 수 있어야 함
- 퀵 정렬


### 이해하는 정도면 충분
- 병합 정렬
- 힙 정렬



## 정렬 알고리즘 비교

| 정렬 알고리즘 | 평균 시간 복잡도    | 최악 시간 복잡도    | 메모리 사용량    | 안정성 |
| ------- | ------------ | ------------ | ---------- | --- |
| 버블 정렬   | $O(N^2)$     | $O(N^2)$     | $O(1)$     | 안정  |
| 선택 정렬   | $O(N^2)$     | $O(N^2)$     | $O(1)$     | 불안정 |
| 삽입 정렬   | $O(N^2)$     | $O(N^2)$     | $O(1)$     | 안정  |
| 퀵 정렬    | $O(N log N)$ | $O(N^2)$     | $O(log N)$ | 불안정 |
| 병합 정렬   | $O(N log N)$ | $O(N log N)$ | $O(N)$     | 안정  |
| 힙 정렬    | $O(N log N)$ | $O(N log N)$ | $O(1)$     | 불안정 |

참고: 
- 평균 시간 복잡도는 평균적으로 소요되는 시간을 나타냅니다.
- 최악 시간 복잡도는 입력이 최악의 경우에 소요되는 시간을 나타냅니다.
- 메모리 사용량은 정렬 알고리즘이 필요로 하는 메모리 양을 나타냅니다.
- 안정성은 동일한 값에 대해 순서가 바뀌지 않음을 의미합니다.


## 시간복잡도와 실제 성능은 다를 수 있다.
- 메모리 할당 / 해제 하는데 많은 시간이 소요된다.
- 시간복잡도와 실행시간은 다르다.(원래 앞에 들어가는 상수가 제거됨, 따라서 앞에 상수를 무시하지 않게 되면 성능 차이가 발생한다)



## 상황에 따른 정렬 알고리즘 선택

### 기본 - 퀵 정렬
- 퀵 정렬 사용
	- C도 qsort()함수를 기본 제공

### 간단히 구현할 때 - 버블 정렬
- 버블 정렬 사용
	- 구현이 매우 쉬움
	- 10년 안써도 까먹을 수 없을 정도

### 어떤 경우에도 느려지면 안될 때 - 병합 또는 힙 정렬
- 병합 또는 힙 정렬
	- 평균은 퀵 정렬보다 느림
	- 최악의 경우 여전히 $O(N log N)$


### 특수한 상황에 적합한 정렬 알고리즘
- 예: 기수(radix) 정렬



# Leetcode explanation

The fundamental problem of sorting is all about ordering a collection of items. How you order these items is entirely based on the method of comparison. Suppose you needed to sort a pile of books. If you are working on a home library, you might organize it by the author’s last name. But if you need to quickly transport the books, it might make sense to initially organize them based on the size of the book. Both of these problems are sorting problems, but a key takeaway is that sorting problems are necessarily tied to a method of comparison. Different methods of comparison may lead to different results. At the most basic level, sorting algorithms are all about rearranging elements in a collection based on a common characteristic of those elements.

In computer science, we have formal definitions of sorting with respect to ordering relations.

An **ordering relation** has two key properties: 1. Given two elements a and b, exactly one of the following must be true: $a < b, a = b, a > b$ ( [**Law of Trichotomy**](https://en.wikipedia.org/wiki/Trichotomy_(mathematics)) ) 2. If $a<b$ and $b < c$, then $a<c$ ( [**Law of Transitivity**](https://en.wikipedia.org/wiki/Transitive_relation) )

A **sort** is formally defined as a rearrangement of a sequence of elements that puts all elements into a non-decreasing order based on the ordering relation.

Suppose you were given a list of strings [“hello”, “world”, “we”, “are”, “learning, “sorting”]. One way to define an ordering relation might be based on the length of the string. One valid sort based on this ordering relation is [“we”, “are”, “hello”, “world”, “sorting”, “learning”]. For every pair of adjacent elements in the list, the length of the preceding string is always less than or equal to the length of the following string. Another ordering relation we could define is the number of vowels in the string. That would lead to the following sort: [“we”, “world”, “are”, “hello”, “sorting”, “learning”].

The ordering relation practically is defined as a method of comparison in programming languages. Most programming languages allow you to pass in custom functions for comparison whenever you want to sort a sequence of elements. In Java, for example, these are comparators. In Python, you can pass a comparison function as the key to the sort method.

```java
import java.util.Arrays;

public class Solution {
    public void sortByLength(String[] arr) {
        // Sorts a list of string by length of each string
        Arrays.sort(array, new StringCompare());
    }
}

public class StringCompare implements Comparator<String> {
    public int compare(String s1, String s2) {
        if (s1.length() > s2.length()) {
            return 1;
        } else if (s1.length() < s2.length()) {
            return -1;
        }
        return 0;
    }
}
```

An important concept in sorting is **inversions**. An inversion in a sequence is defined as a pair of elements that are out of order with respect to the ordering relation. To understand this idea better, let's consider our earlier string example, where the ordering relation was defined by the length of the string:

[“are”, “we”, “sorting”, “hello”, “world”, “learning”]

Clearly, the above list is not sorted according to the lengths of strings, but what if you had to define a metric for how “out of sort” it was? Inversions provide a way to define that. In the above unsorted list, we have the following inversions:

(“are”, “we”), (“sorting”, “hello”)(“sorting”, “hello”), and (“sorting”, “world”)(“sorting”, “world”)

The more inversions present, the more out of order the list is. In fact, the concept of inversions introduces an alternative definition of sorting: Given a sequence of elements with n inversions, a **sorting algorithm is a sequence of operations that reduces inversions to 0**.

The next important concept in sorting that we will refer back to is the **stability** of sorting algorithms. The key feature of a stable sorting algorithm is that it will preserve the order of equal elements. In our earlier string example with the string length ordering comparison, our original sequence was

[“hello”, “world”, “we”, “are”, “learning, “sorting”]

There are two valid sorts for this sequence:

1. [“we”, “are”, “hello”, “world”, “sorting”, “learning”]
2. [“we”, “are”, “world”, “hello”, “sorting”, “learning”]

We consider (1) to be a stable sort since the equal elements “hello” and “world” are kept in the same relative order as the original sequence.

