## 정렬된 배열 합치기는 효율적
- 시간 복잡도: O(N)
- 단, 배열 하나를 더 만들었음
	- 공간복잡도: O(N)
- 정렬된 데이터에 사용할 수 있는 효율적 알고리즘의 간단한 예

## 정렬된 배열들이 필요하다!
- 우선 원본 배열을 정렬된 여러 배열들로 만듦
	- 단, 원본 배열을 정렬하면 안됨
- 그 다음 정렬된 배열들을 아까 본 방법으로 합치면 끝

## 병합 정렬
1. 입력 배열을 재귀적으로 반씩 나눠 요소 수가 1인 배열들을 만듦
	- 요소 수가 1이니 정렬된 배열
	- 정확히 반씩 나누니 재귀 깊이는 $O(log N)$
2. 재귀 반대 방향으로 배열을 계속 합침
	- 이때 정렬된 상태를 유지해야 함
	- 각 재귀 단계마다 방문하는 요소 수는 $O(N)$
3. 제일 상위 단계까지 합치면 정렬 끝


```java
public class MergeSort {
    public static void mergeSort(int[] array) {
        if (array == null) {
            return;
        }
        if (array.length > 1) {
            int mid = array.length / 2;
            int[] leftArray = new int[mid];
            int[] rightArray = new int[array.length - mid];

            System.arraycopy(array, 0, leftArray, 0, mid);
            System.arraycopy(array, mid, rightArray, 0, array.length - mid);

            mergeSort(leftArray);
            mergeSort(rightArray);

            merge(array, leftArray, rightArray);
        }
    }

    public static void merge(int[] array, int[] leftArray, int[] rightArray) {
        int leftIndex = 0, rightIndex = 0, mergedIndex = 0;

        while (leftIndex < leftArray.length && rightIndex < rightArray.length) {
            if (leftArray[leftIndex] < rightArray[rightIndex]) {
                array[mergedIndex++] = leftArray[leftIndex++];
            } else {
                array[mergedIndex++] = rightArray[rightIndex++];
            }
        }

        while (leftIndex < leftArray.length) {
            array[mergedIndex++] = leftArray[leftIndex++];
        }

        while (rightIndex < rightArray.length) {
            array[mergedIndex++] = rightArray[rightIndex++];
        }
    }

```

