#include <cstdio>
int D[301][301]; // 연산 횟수 저장

int f(int n, int m)
{
	if (n == 0 || m == 0) return 0;
	if (n == 1 && m == 1) return 0;
	if (D[n][m]) return D[n][m];

	if (n == 1) return D[n][m] = 1 + f(n, m / 2) + f(n, (m + 1) / 2);
	return D[n][m] = 1 + f(n / 2, m) + f((n + 1) / 2, m);
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	printf("%d", f(N, M));

	return 0;
}