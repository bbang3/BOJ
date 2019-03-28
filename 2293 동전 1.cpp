#include <cstdio>
#include <memory.h>
#include <algorithm>
int N, K;
int coin[105];
int dp[10005];// dp[i] : i원을 만드는 경우의 수
			  // dp[i] += dp[i-coin[j]]
int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%d", coin + i);

	dp[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = coin[i]; j <= K; j++)
		{
			dp[j] += dp[j - coin[i]];
		}
	}
	printf("%d", dp[K]);
	return 0;
}