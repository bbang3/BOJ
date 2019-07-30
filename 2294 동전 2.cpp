#include <cstdio>
#include <memory.h>
#include <algorithm>
int N, S;
int coin[105];
int D[10005]; // dp[i] : i원을 만들기 위한 최소 동전 개수
			   // dp[i] = min(dp[i],dp[i - coin[j]] + 1)
#define INF 987654321
int main()
{
	scanf("%d %d", &N, &S);
	for (int i = 1; i <= N; i++) scanf("%d", coin + i);
	for (int i = 1; i <= S; i++) D[i] = INF;
	D[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = coin[i]; j <= S; j++)
		{
			if (D[j - coin[i]] == INF) continue;
			D[j] = std::min(D[j], D[j - coin[i]] + 1);
		}
	}
	printf("%d", D[S] == INF ? -1 : D[S]);
	return 0;
}