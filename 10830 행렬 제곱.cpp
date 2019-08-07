#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MOD = 1e3;

ll ans[50 + 5][50 + 5] = { 0 };
ll mat[50 + 5][50 + 5];
int N;
ll B;

void matpro(ll m1[55][55], ll m2[55][55])
{
	ll res[55][55] = { 0 };

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
				res[i][j] = (res[i][j] % MOD + m1[i][k] * m2[k][j] % MOD) % MOD;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			m1[i][j] = res[i][j];
}

int main()
{
	scanf("%d %lld", &N, &B);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &mat[i][j]);
	for (int i = 1; i <= N; i++) ans[i][i] = 1;

	while (B)
	{
		if (B & 1LL) matpro(ans, mat);
		matpro(mat, mat);
		B >>= 1;
	}

	for (int i = 1; i <= N; i++, puts(""))
		for (int j = 1; j <= N; j++)
			printf("%d ", ans[i][j]);

	return 0;
}