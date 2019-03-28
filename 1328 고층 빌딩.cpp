#include <cstdio>
#include <math.h>

const int MOD = 1000000007;
int N, L, R;
long long D[105][105][105];

int main()
{
	scanf("%d %d %d", &N, &L, &R);
	D[1][1][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int L = 1; L <= i; L++)
		{
			for (int R = 1; R <= i; R++)
			{
				D[i][L][R] = (D[i - 1][L][R - 1] % MOD + D[i - 1][L - 1][R] % MOD) + ((D[i - 1][L][R] * (i - 2)) % MOD) % MOD;
			}
		}
	}

	printf("%lld", D[N][L][R] % MOD);
	return 0;
}