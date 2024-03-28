
## Problem Definition
- Text: Simple String of Characters
- Pattern: Simple String of Characters
- To Do: Find where in the Text the Pattern Occurs



## BruteForce(Naive)


```c
int naivematch(char T[], int n, char P[], int m, int output[]){
	int i, j, k, kk;
	for(i=0; i<n; i++){
		for(j =0; j<m; j++){
			if(T[i+j] == P[j]) output[i+j] = max(output[i+j], j+1);
			else break;
		}
	}
}
```


## DFA(Deterministic Finite Automaton, deterministic fnide omoamtá)

DFA(Deterministic Finite Automaton, deterministic fnide omoamtá)는 정규 언어를 인식하는 유한 오토마타의 한 종류입니다. DFA는 문자열이 주어진 패턴에 매칭되는지 여부를 결정하는 데 사용됩니다.

DFA는 다음과 같은 5개의 요소로 구성됩니다.

1. **유한 상태 집합(Q)**: 오토마타가 가질 수 있는 상태들의 집합입니다.
2. **알파벳 집합(Σ)**: 입력 문자열에 포함될 수 있는 문자들의 집합입니다.
3. **전이 함수(δ)**: 현재 상태와 입력 문자에 따라 다음 상태를 결정하는 함수입니다.
4. **시작 상태(q0)**: 초기 상태입니다.
5. **종료 상태 집합(F)**: 문자열이 패턴에 매칭되는지 여부를 나타내는 상태들의 집합입니다.

DFA의 동작 원리는 다음과 같습니다.

1. 시작 상태(q0)에서 출발합니다.
2. 입력 문자열의 각 문자를 하나씩 읽으며, 현재 상태와 입력 문자에 따라 전이 함수(δ)를 적용하여 다음 상태로 이동합니다.
3. 입력 문자열의 모든 문자를 읽은 후, 최종 상태가 종료 상태 집합(F)에 포함되어 있다면 문자열이 패턴에 매칭되는 것으로 판단합니다.

DFA는 deterministic(결정론적)이기 때문에, 주어진 상태와 입력 문자에 대해 유일한 다음 상태가 존재합니다. 이는 DFA가 효율적이고 예측 가능한 실행을 보장한다는 장점이 있습니다.

DFA는 정규 표현식, 컴파일러, 텍스트 편집기, 네트워크 프로토콜 등 다양한 분야에서 활용됩니다. 특히 정규 표현식을 DFA로 변환하여 문자열 매칭을 수행하는 방법이 널리 사용됩니다.

예를 들어, 정규 표현식 `a(b|c)*d`를 인식하는 DFA는 다음과 같이 나타낼 수 있습니다.

```
상태 집합(Q) = {0, 1, 2, 3}
알파벳 집합(Σ) = {a, b, c, d}
전이 함수(δ):
    δ(0, a) = 1
    δ(1, b) = 1
    δ(1, c) = 1
    δ(1, d) = 2
시작 상태(q0) = 0
종료 상태 집합(F) = {2, 3}
```

이 DFA는 `a`로 시작하고, 그 다음에 `b`나 `c`가 0개 이상 있고, 마지막에 `d`가 오는 문자열을 인식합니다.

DFA는 문자열 패턴 매칭 문제를 효율적으로 해결할 수 있는 강력한 도구입니다. 그러나 모든 정규 언어를 인식할 수 있는 것은 아니며, 더 복잡한 패턴을 인식하기 위해서는 NFA(Non-deterministic Finite Automaton)와 같은 다른 유한 오토마타를 사용해야 합니다.


## KMP(Knuth-Morris-Pratt)

KMP(Knuth-Morris-Pratt) 알고리즘은 문자열 매칭에 사용되는 효율적인 알고리즘입니다. 주어진 문자열에서 특정 패턴을 찾는 데 사용됩니다.

기본 아이디어는 패턴 매칭 과정에서 текст에 대해 이미 비교한 정보를 활용하여 불필요한 비교를 줄이는 것입니다.

예를 들어 "ABABCABCAB" 텍스트에서 패턴 "ABCAB"를 찾는 경우를 생각해봅시다.

1. 처음에는 텍스트의 시작부터 패턴과 문자를 하나씩 비교합니다.
2. 불일치가 발생하면 이전에 이미 비교한 결과를 활용하여 패턴에서 얼마나 건너뛰어야 하는지 계산합니다.
3. 이를 위해 KMP는 패턴에 대한 부분 일치 테이블(partial match table)을 계산합니다.
4. 부분 일치 테이블은 패턴의 접두사(prefix)와 접미사(suffix)가 일치하는 최대 길이를 저장합니다.
5. 불일치 시 이 테이블을 참조하여 패턴을 적절히 이동시킵니다.

KMP의 시간 복잡도는 O(m+n)으로 상대적으로 효율적입니다. 여기서 m은 패턴의 길이, n은 텍스트의 길이입니다.

패턴 매칭에 Brute-Force 방식을 사용하면 O(mn)의 시간 복잡도를 가지므로, KMP가 더 효율적입니다.


```c
#include <stdio.h>
#include <string.h>

void computeLPSArray(char *pat, int m, int *lps) {
    int len = 0;
    lps[0] = 0; // lps[0] is always 0

    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *pat, char *txt) {
    int m = strlen(pat);
    int n = strlen(txt);

    int lps[m];

    computeLPSArray(pat, m, lps);

    int i = 0;  // index for txt[]
    int j = 0;  // index for pat[]
    while (i < n) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main() {
    char txt[] = "ABABCABCABCAB";
    char pat[] = "ABCAB";
    KMPSearch(pat, txt);
    return 0;
}
```