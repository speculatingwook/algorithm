### 정의
연속된 주소, 동일한 type

### 장점
n개중 k번째 access가 상수 시간에 가능. Search가 빠름

### 단점
크기 변화 비용이 크다. Inserte, Delete가 느릴 수 있다.

### 사용
변화가 없거나 드문 자료


## Linear Search
```c
int search(int a[], int n, int x){
	int i;
	for (i=0; i<n; i++)
		if (a[i] == x) return i;
	return -1;
}
```


```c
int search(int a[], int n, int x){
	int i;
	for(i=0; i<n; i++)
		if(*(a+i) == x) return i;
	return -1;
}
```

## Binary Search
```c
int search(int a[], int n, int x){
	int l, r, m;
	l=0; r = n-1;
	while (l<=r){
		m = (l + r) / 2;
		if (a[m] < x)
			l = m+1;
		le
	}
}
```