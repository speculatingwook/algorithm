- 실무에서 가장 많이 사용하는 정렬
	- 일반적 / 범용적으로 가장 빠름
- 진정한 분할 정복 알고리즘
	- 모든 요소를 방문함(decrease - and-counquer와의 차이)
	- 복잡도에 logr가 있다는 것에서 알 수 있음
- 어떤 값(pivot)을 기준으로 목록을 하위 목록으로 2개로 나눔
	- 목록을 나누는 기준은 pivot보다 작냐/크냐
	- 이 과정을 재귀적으로 반복
	- 재귀 단계가 깊어질 때마다 새로운 pivot 값을 뽑음


```java
public static void quickSort(int[] nums){
	quickSortRecursive(nums, 0, nums.length - 1);
}

public static quickSortRecursive(int[] nums, int left, int right) {
	if (left >= right) {
		return;
	}
	
	int pivotPos = partition(nums, left, right);
	
	qickSortRecursive(nums, left, pivotPos - 1);
	quickSortRecursive(nums, pivotPos + 1, right);
}

public static int partition(int[] nums, int left, int right) {
	int pivot = nums[right];
	
	// 혹시라도 swap()이 한번도 안일어나면 left 위치로 기준값을 옮기기 위해 1 감소
	int i = (left - 1); 
	for(int j = left; j < right; ++j){
		if(nums[j] < pivot) {
			++i;
			swap(nums, i, j);
		}
	}
	
	int pivotPos = i + 1;
	swap(nums, pivotPos, right);
	
	return pivotPos;
}
```
