## 스택(stack)

LIFO(Last In First Out) 형태로 데이터를 저장하는 구조

## 스택의 주요 동작

### push
- 스택의 가장 위에 새로운 데이터를 추가하는 작업

### pop  
- 스택의 가장 위에 있는 데이터를 제거하고, 그 값을 반환하는 작업

### peek
- 스택의 가장 위에 있는 데이터를 반환하되, 제거하지는 않는 작업

## 스택 사용 사례: stack memory & stack frame
- 프로그램 실행 시 함수 호출과 관련된 정보(매개변수, 반환 주소 등)를 저장하는 메모리 영역으로 스택이 사용
- 각 함수 호출마다 스택 프레임(stack frame)이 생성되어 관련 정보가 푸시(push)되고, 함수 종료 시 해당 프레임이 팝(pop)

## StackOverflowError
- 재귀함수(recursive function)에서 탈출 못해서 발생
- 스택 메모리가 가득 차서 더 이상 스택 프레임을 저장할 수 없을 때 발생하는 에러

## 큐(Queue)  

FIFO(First In First Out) 형태로 데이터를 저장하는 구조

## 큐의 주요 동작

### enqueue
- 큐의 뒤쪽에 새로운 데이터를 추가하는 작업

### dequeue
- 큐의 앞쪽에 있는 데이터를 제거하고, 그 값을 반환하는 작업  

### peek
- 큐의 앞쪽에 있는 데이터를 반환하되, 제거하지는 않는 작업

## 큐 사용사례: producer/consumer architecture
- 생산자(producer)와 소비자(consumer) 프로세스 간의 데이터 교환을 위해 큐가 사용
- 생산자는 큐에 데이터를 enqueue하고, 소비자는 큐에서 dequeue하여 데이터를 처리

## OutOfMemoryError
- Java의 힙(heap) 메모리를 다 썼을 때 발생  
- 큐에 데이터가 계속 쌓이기만 한다면 발생할 수 있음
- 메모리 누수(memory leak)나 과도한 메모리 사용으로 인해 발생할 수 있음