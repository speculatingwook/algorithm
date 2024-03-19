- 간단한 정렬 알고리즘 중 하나
- 목록을 총 N-1번 훑으면서 다음 과정을 반복
	- 첫번째 요소 0부터 훑으면서 최솟값을 찾아 요소 0과 교환
	- 두번째는 요소 1부터 훑으면서 최솟값을 찾아 요소 1과 교환
	- 세번째는 요소 2부터 훑으면서 최솟값을 찾아 요소 2와 교환
	- N-1번째까지 반복
- 최솟값을 찾아 선택한다고 해서 선택 정렬



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