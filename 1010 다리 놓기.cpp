#include <cstdio>
using namespace std;

int dp[30][30];

int ncr(int n, int r)
{
	if (r > n) return 0;
	if (dp[n][r])
		return dp[n][r];
	if (r == 1) return dp[n][r] = n;
	if (r == 0) return dp[n][r] = 1;
	
	return dp[n][r] = ncr(n - 1, r - 1) + ncr(n - 1, r);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%d\n", ncr(m, n));
	}
	return 0;
}