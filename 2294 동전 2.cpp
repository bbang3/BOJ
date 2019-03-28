#include <cstdio>
#include <memory.h>
#include <algorithm>
int N, K;
int coin[105];
int dp[10005]; // dp[i] : i원을 만들기 위한 최소 동전 개수
			   // dp[i] = min(dp[i],dp[i - coin[j]] + 1)
#define INF 987654321
int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%d", coin + i);
	for (int i = 1; i <= K; i++) dp[i] = INF;
	dp[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = coin[i]; j <= K; j++)
		{
			if (dp[j - coin[i]] == INF) continue;
			dp[j] = std::min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	printf("%d", dp[K] == INF ? -1 : dp[K]);
	return 0;
}