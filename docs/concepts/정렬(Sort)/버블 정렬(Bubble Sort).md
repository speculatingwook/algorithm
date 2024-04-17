- 가장 간단한 정렬 알고리즘중 하나
	- 기본기 중의 기본기
	- 스스로 이 알고리즘을 고안하지 못해도 됨
	- 하지만 한 번이라도 이해하면 언제라도 작성 가능해야 함
- 이웃 요소 둘을 비교해서 올바른 순서로 고치는 과정을 반복
- 한 번 목록을 순회할 때마다 가장 큰 값이 제일 위로 올라감
	- 기포가 수면으로 떠오르는 모습을 닮았다고 해서 버블 정렬
	- 큰 기포일수록 수면으로 더 빨리 떠오름

Bubble sort is an implementation of a rather simple idea. Suppose we have a collection of integers that we want to sort in ascending order. Bubble sort proceeds to consider two adjacent elements at a time. If these two adjacent elements are out of order (in this case, the left element is strictly greater than the right element), bubble sort will swap them. It then proceeds to the next pair of adjacent elements. In the first pass of bubble sort, it will process every set of adjacent elements in the collection once, making swaps as necessary. The core idea of bubble sort is it will repeat this process until no more swaps are made in a single pass, which means the list is sorted.


In terms of the running time of the algorithm, bubble sort's runtime is entirely based on the number of passes it must make in the array until it's sorted. If the array has n elements, each pass will consider $(n - 1)$  pairs. In the worst case, when the minimum element is at the end of the list, it will take $(n - 1)$  passes to get it to the proper place at the front of the list, and then one more additional pass to determine that no more swaps are needed. Bubble sort, as a result, has worst case runtime of $O(n^2)$. The space complexity of bubble sort is $O(1)$. All sorting operations involve swapping adjacent elements in the original input array, so no additional space is required.

Bubble sort is also a **stable** sorting algorithm since equal elements will never have swapped places, so their relative ordering will be preserved.

Overall, bubble sort is fairly simple to implement, and it’s stable, but outside of that, this algorithm does not have many desirable features. It’s fairly slow for most inputs and, as a result, it is rarely used in practice.

```java
public static void bubbleSort(int[] nums){
	for(int i =0; i< nums.length - 1; i++){
		for(int j =0; j < nums.length -1 - i; j++ ){
			if(nums[j]>nums[j+1]){
				int temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
		}
	}
}
```

```java
public class Solution {
    public void bubbleSort(int[] arr) {
        // Mutates arr so that it is sorted via swapping adjacent elements until
        // the arr is sorted.
        boolean hasSwapped = true;
        while (hasSwapped) {
            hasSwapped = false;
            for (int i = 0; i < arr.length - 1; i++) {
                if (arr[i] > arr[i + 1]) {
                    // Swap adjacent elements
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    hasSwapped = true;
                }
            }
        }
    }
}
```