#include <cstdio>
#include <algorithm>
using namespace std;

/* 
�ȶ��� brute force 
������ �Ű� ���ο� ���� ���� ������ ��
�׷����� �� ���¿��� �ٸ� ���·� �̵��ϴ� ����� ���� ������
*/
int A, B, C, D;

int AtoB(int a, int b) // (A, 0)���� �����Ͽ� ���ϴ� ���� �� �����
{
	if (a == A && b == B) return 987654321; // �� �� ���� ��� -> ����Ŭ -> �ذ� ����
	if (a == C && b == D) return 0; // ���ϴ� ��� ����� ����(����� Ƚ�� �߰� X)

	if (a == 0)	return 1 + AtoB(A, b); // A������ ��� ������ ���� ä��
	if (b == B) return 1 + AtoB(a, 0); // B������ ���� ����

	if (b + a > B) return 1 + AtoB(a - (B - b), B); // A���뿡�� B�������� �̵�
	else return 1 + AtoB(0, b + a);

}

int BtoA(int a, int b) // (0, B)���� �����Ͽ� ���ϴ� ���� �� �����
{
	if (a == A && b == B) return 987654321;
	if (a == C && b == D) return 0;

	if (b == 0)	return 1 + BtoA(a, B); // B������ ��� ������ ���� ä��
	if (a == A) return 1 + BtoA(0, b); // A������ ���� ����

	if (a + b > A) return 1 + BtoA(A, b + a - A); // B���뿡�� A�������� �̵�
	else return 1 + BtoA(b, 0);
}

int main()
{
	scanf("%d %d %d %d", &A, &B, &C, &D);

	int ans = 0;
	if (A == C && B == D) ans = 2; // ��� ���� �� ����
	else ans = min(AtoB(0, 0), BtoA(0, 0)); // �� ��� �� ���� Ƚ�� ����

	if (ans >= 987654321) puts("-1"); // ���� �� ������ -1 ���
	else printf("%d", ans);

	return 0;
}