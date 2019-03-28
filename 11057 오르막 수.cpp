#include <cstdio>
#include <memory.h>

const int MOD = 10007;

int N;
int D[1005][11];
int main()
{
	scanf("%d", &N);

	D[0][0] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= j; k++)
				D[i][j] += D[i - 1][k] % MOD;
		}
	}
	int sum = 0;
	for (int i = 0; i <= 9; i++) sum += D[N][i];
	printf("%d", sum % 10007);
	return 0;
}