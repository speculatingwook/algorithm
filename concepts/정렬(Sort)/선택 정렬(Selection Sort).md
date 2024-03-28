- 간단한 정렬 알고리즘 중 하나
- 목록을 총 N-1번 훑으면서 다음 과정을 반복
	- 첫번째 요소 0부터 훑으면서 최솟값을 찾아 요소 0과 교환
	- 두번째는 요소 1부터 훑으면서 최솟값을 찾아 요소 1과 교환
	- 세번째는 요소 2부터 훑으면서 최솟값을 찾아 요소 2와 교환
	- N-1번째까지 반복
- 최솟값을 찾아 선택한다고 해서 선택 정렬

Suppose we had a collection of elements where every element is an integer. Selection sort will build up the sorted list by repeatedly finding the minimum element in that list and moving it to the front of the list through a swap. It will proceed to swap elements appropriately until the entire list is sorted.

In terms of simplicity, it is a highly intuitive algorithm and not too difficult to write. Unfortunately, it is pretty slow, requiring �(�2)O(n2) time to sort the list in the worst case. In the worst case, we have to search the entire array to find the minimum element, meaning we can have up to �+(�−1)+(�−2)+…+1n+(n−1)+(n−2)+…+1 total operations, which is �(�2)O(n2). The space complexity of selection sort is �(1)O(1) since we do not use any additional space during the algorithm (all operations are in-place).

It also is **not a stable** sorting algorithm. For example consider the collection [**4**, 2, 3, 4, 1]. After the first round of selection sort, we get the array [1, 2, 3, 4, **4**]. This array is sorted, but it does not preserve the ordering of equal elements.

```java
public static void selectionSort(int[] nums){
	for(int i = 0; i< nums.length - 1; i++){
		int minIndex = i;
		for(int j = i + 1; j < nums.length; j++){
			if(nums[j]< arr[minIndex]){
				minIndex = j;
			}
		}
		if(minIndex != i){
			int temp = nums[minIndex];
			nums[minIndex] = nums[i];
			arr[i] = temp;
		}
	}
}
```



## example problem


### Sort Colors
Given an array `nums` with `n` objects colored red, white, or blue, sort them **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.


**Example 1:**

**Input:** nums = [2,0,2,1,1,0]
**Output:** [0,0,1,1,2,2]


**Example 2:**

**Input:** nums = [2,0,1]
**Output:** [0,1,2]

**Constraints:**

- `n == nums.length`
- `1 <= n <= 300`
- `nums[i]` is either `0`, `1`, or `2`.


```java
class Solution {
    public void sortColors(int[] nums) {
        for(int i=0; i<nums.length; i++){
            int minIndex = i;
            for(int j = i+1; j<nums.length; j++){
                if(nums[minIndex] >= nums[j]){
                    minIndex = j;
                }
            }
            int temp = nums[i];
            nums[i] = nums[minIndex];
            nums[minIndex] = temp;
        }
    }
}
```

