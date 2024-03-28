
## Problem Definition
- Text: Simple String of Characters
- Pattern: Simple String of Characters
- To Do: Find where in the Text the Pattern Occurs






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


