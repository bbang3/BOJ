#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int D[3][1000 + 5];
// D[i][0] : i��° ���� ��ƼĿ�� ���� ����, [1] : i��° ���� ���� ��ƼĿ ����, [2] : i��° ���� �Ʒ��� ��ƼĿ ����
int wine[3][1000 + 5];
int N;

int f(int color, int i) // i��° ���� color�� ĥ���� �� �ּ� ��� (0 - R, 1 - G, 2 - B)
{
	if (i == 0) return 0;
	if (D[color][i] != -1) return D[color][i];

	if (color == 0)
	{
		D[color][i] = min(f(1, i - 1), f(2, i - 1)) + wine[color][i];
	}
	else if (color == 1)
	{
		D[color][i] = min(f(0, i - 1), f(2, i - 1)) + wine[color][i];
	}
	else D[color][i] = min(f(0, i - 1), f(1, i - 1)) + wine[color][i];

	return D[color][i];
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) scanf("%d %d %d", &wine[0][i], &wine[1][i], &wine[2][i]);
	memset(D, -1, sizeof(D));

	printf("%d", min(f(0, N), min(f(1, N), f(2, N))));

	return 0;
}