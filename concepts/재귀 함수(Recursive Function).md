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



## 재귀함수의 장단점


### 장점
- 가독성이 좋음
- 코드가 짧음
- 각 단계의 변수 상태가 자동 저장됨
	- 함수의 스택 프레임 덕분
- 코드 검증도 쉬움

### 단점
- 재귀적 문제 분석/설계가 안 직관적
- 맹목적인 믿음이 필요
	- 수학적 귀납법을 이해하면 믿음이 생김
- 스택 오버플로 발생 가능
	- 재귀 함수 호출이 너무 깊은 경우
- 함수 호출에 따른 과부하


## 읽기 좋은 코드 작성이 기본(현업)
- 기본적으로 재귀 함수를 사용하는 게 나은 방법
	- 가독성이 좋고 유지보수가 쉬운 코드가 더 중요
- 다음과 같을 경우 반복문으로 변환
	- 스택 오버플로우가 날 가능성이 있는 경우
	- 성능 문제가 일어날 가능성이 큰 경우
	- 성능 문제가 확인된 경우
- 모든 재귀함수는 반복문으로 작성 가능
	- 복잡한 경우 스택 등의 데이터 구조를 사용해야 함



## 꼬리 호출(tail call)
- 함수 코드 제일 마지막에서 다른 함수를 호출하는 경우
- 그 후에 실행하는 명령어가 없음
```java
public int calculateSignature(int[] data, int multiplier) {
	int[] tempData = new int[data.length];
	for(int i =0; i< data.length; ++i) {
		tempData[i] = data[i] * multiplier;
	}
	
	return accumulate(tempData);
}
```

## 꼬리 호출과 스택 프레임
- 스택 프레임이 존재하는 이유
	- 함수에서 사용중인 변수 값을 유지하기 위해
	- 타 함수 호출 후 반환되면 스택에 저장했던 값을 되돌려 사용
- 꼬리 호출의 경우는 타 함수로부터 반환 후 더 이상 연산이 없음
	- 곧바로 호출자로 반환
- 따라서 스택 프레임에 저장해 놓은 변수 값을 재사용하지 않음
- 이런 경우 컴파일러가 스택 프레임을 따로 안 만드는 최적화를 하기도 함
	- 꼬리 호출 제거(tail call elimination)
	- 꼬리 호출 최적화(tail call optimization)


## 꼬리 재귀(tail recursion)
- 꼬리 호출의 특수한 경우
- 마지막에 호출하는 함수(꼬리 호출)가 자기 자신(재귀)
- 꼬리 호출과 똑같은 최적화가 적용됨


- 팩토리얼 꼬리 재귀 함수

```java
int factorial(int n){
	return factorialRecursive(n, 1);
}

int factorialRecursive(int n, int fac) {
	if (n <= 1){
		return fac;
	}
	return factorialRecursive(n-1, n * fac);
}

```

- 계산에 대한 책임? 을 함수 매개변수로 줌(스택 프레임이 아님)


## 꼬리 재귀 함수 작성하기
- 보통 꼬리 재귀 함수가 덜 직관적
- 그러나 이런 식으로 작성된 코드가 종종 보임
- 가장 큰 이유는 앞에서 말했던 최적화
- 하지만 꼬리 호출 최적화를 지원 안하는 언어라면?
	- 안 돼도 충분한 의미가 있음
	- 꼬리 재귀는 반복문으로 쉽게 변경 가능!

