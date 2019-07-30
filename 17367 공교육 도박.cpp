#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <memory.h>
using namespace std;

//���� ���� 3���� ������ 10, 000�� + (���� ��) * 1, 000���� ����� �ް� �ȴ�.
//���� ���� 2���� ������ ��쿡�� 1, 000�� + (���� ��) * 100���� ����� �ް� �ȴ�.
//��� �ٸ� ���� ������ ��쿡��(�� �� ���� ū ��) * 100���� ����� �ް� �ȴ�.

int N;
double D[10][10][10][1000 + 5];
// D[i][j][k][n] : n�� �ֻ����� ������ �� ������ 3ȸ�� i,j,k(���� �ֱ�)�� �� ���

int getscore(int a, int b, int c)
{
	if (a == b && b == c) return 10000 + 1000 * a;
	else if (a == b || a == c)
		return 1000 + 100 * a;
	else if (b == c)
		return 1000 + 100 * b;
	else return max({ a, b, c }) * 100;
}

double dice(int i, int j, int k, int n)
{
	if (D[i][j][k][n] != 0) return D[i][j][k][n];
	if (n == N) return getscore(i, j, k);

	for (int next = 1; next <= 6; next++)
	{
		D[i][j][k][n] += dice(j, k, next, n + 1);
	}
	return D[i][j][k][n] = max((double)getscore(i, j, k), D[i][j][k][n] / 6.0);
}

int main()
{
	scanf("%d", &N);

	double ans = 0;
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			for (int k = 1; k <= 6; k++)
				ans += dice(i, j, k, 3);


	printf("%lf", ans / 216);


	return 0;
}