- 가장 간단한 정렬 알고리즘중 하나
	- 기본기 중의 기본기
	- 스스로 이 알고리즘을 고안하지 못해도 됨
	- 하지만 한 번이라도 이해하면 언제라도 작성 가능해야 함
- 이웃 요소 둘을 비교해서 올바른 순서로 고치는 과정을 반복
- 한 번 목록을 순회할 때마다 가장 큰 값이 제일 위로 올라감
	- 기포가 수면으로 떠오르는 모습을 닮았다고 해서 버블 정렬
	- 큰 기포일수록 수면으로 더 빨리 떠오름


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