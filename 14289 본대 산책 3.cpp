#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll ans[50 + 5][50 + 5] = { 0 };
ll mat[50 + 5][50 + 5];
int N, M, D;

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
	scanf("%d %d", &N, &M);
	while (M--)
	{
		int src, dest;
		scanf("%d %d", &src, &dest);
		mat[src][dest] = mat[dest][src] = 1;
	}
	scanf("%d", &D);
	// 인접 행렬의 n제곱 -> n개의 정점을 거쳐 가는 경우의 수
	for (int i = 1; i <= N; i++) ans[i][i] = 1;
	while (D > 0)
	{
		if (D % 2 == 1) matpro(ans, mat);
		matpro(mat, mat);
		D >>= 1;
	}
	printf("%lld", ans[1][1]);

	return 0;
}