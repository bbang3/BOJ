#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = 1e9;
int N;
int D[100 + 5][10 + 5][(1 << 10) + 5];


int f(int len, int curn, int status)
{
	if (len == N)
	{
		if (status == (1 << 10) - 1)
			return 1;
		return 0;
	}
	int& ret = D[len][curn][status];
	if (ret != -1) return ret;

	if (curn == 0)
		ret = f(len + 1, curn + 1, status | (1 << (curn + 1))) % MOD;
	else if (curn == 9)
		ret = f(len + 1, curn - 1, status | (1 << (curn - 1))) % MOD;
	else
		ret = (f(len + 1, curn + 1, status | (1 << (curn + 1))) % MOD + f(len + 1, curn - 1, status | (1 << (curn - 1))) % MOD) % MOD;

	return ret;
}

int main()
{
	memset(D, -1, sizeof(D));
	scanf("%d", &N);
	int ans = 0;
	for (int i = 1; i <= 9; i++)
	{
		ans = (ans + f(1, i, 1 << i)) % MOD;
	}
	printf("%d", ans);
	return 0;
}