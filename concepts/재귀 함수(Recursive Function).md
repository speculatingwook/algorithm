- 아주 쉬운게 아닌 이상 재귀가 필요한 알고리즘이 많다
	- 예: 이진 탐색, 트리 탐색, 퀵 정렬, 그래프 알고리즘
- 큰 문제를 반복 적용 가능한 작은 문제로 나눠 푸는 방법
- 어떤 함수가 매개변수만 바꾸어 자기 스스로를 호출하는 방식으로 구현
- 하노이의 탑정도는 풀 정도로 해야 함


## 재귀 함수의 간단한 예: 피보나치 수열
- 제 0항의 값은 0
- 제 1항의 값은 1
- 그 뒤의 모든 항은 바로 앞 두 항의 합
![](images/pibonacci_1.png)

- 수학적 정의
$F_0 = 0$,
$F_1 = 1$,
$F_n = F_{n - 1} + F_{n -2} \, , (n > 1)$


```java
public static int fibonacciRecursive(int number) {
	if (number <= 1){
		return number;	
	}
	
	return fibonacciRecursive(number - 2) + fibonacciRecursive(number - 1);
}
```

