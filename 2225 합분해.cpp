#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

const int MOD = 1e9;
int N, S;
long long D[200 + 5][200 + 5];

int f(int n, int k)
{
	if (k == 1) return D[n][k] = 1;
	if (D[n][k] != -1) return D[n][k];

	D[n][k] = 0;
	for (int i = 0; i <= n; i++)
	{
		D[n][k] = (D[n][k] + f(n - i, k - 1)) % MOD;
	}

	return D[n][k];
}

int main()
{
	scanf("%d %d", &N, &S);

	memset(D, -1, sizeof(D));
	printf("%d", f(N, S));
	return 0;
}