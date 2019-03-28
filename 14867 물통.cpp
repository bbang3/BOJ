#include <cstdio>
#include <algorithm>
using namespace std;

/* 
똑똑한 brute force 
물통을 옮겨 새로운 물의 양을 만들어야 함
그러려면 한 상태에서 다른 상태로 이동하는 경우의 수가 한정됨
*/
int A, B, C, D;

int AtoB(int a, int b) // (A, 0)에서 시작하여 원하는 물의 양 만들기
{
	if (a == A && b == B) return 987654321; // 둘 다 차는 경우 -> 사이클 -> 해가 없음
	if (a == C && b == D) return 0; // 원하는 경우 만들면 종료(종료시 횟수 추가 X)

	if (a == 0)	return 1 + AtoB(A, b); // A물통이 비어 있으면 가득 채움
	if (b == B) return 1 + AtoB(a, 0); // B물통이 차면 버림

	if (b + a > B) return 1 + AtoB(a - (B - b), B); // A물통에서 B물통으로 이동
	else return 1 + AtoB(0, b + a);

}

int BtoA(int a, int b) // (0, B)에서 시작하여 원하는 물의 양 만들기
{
	if (a == A && b == B) return 987654321;
	if (a == C && b == D) return 0;

	if (b == 0)	return 1 + BtoA(a, B); // B물통이 비어 있으면 가득 채움
	if (a == A) return 1 + BtoA(0, b); // A물통이 차면 버림

	if (a + b > A) return 1 + BtoA(A, b + a - A); // B물통에서 A물통으로 이동
	else return 1 + BtoA(b, 0);
}

int main()
{
	scanf("%d %d %d %d", &A, &B, &C, &D);

	int ans = 0;
	if (A == C && B == D) ans = 2; // 재귀 조건 중 예외
	else ans = min(AtoB(0, 0), BtoA(0, 0)); // 두 방법 중 적은 횟수 선택

	if (ans >= 987654321) puts("-1"); // 만들 수 없으면 -1 출력
	else printf("%d", ans);

	return 0;
}