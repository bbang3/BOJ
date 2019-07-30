#include <cstdio>
#include <memory.h>
#include <algorithm>
int N, S;
int coin[105];
int D[10005];// dp[i] : i원을 만드는 경우의 수
			  // dp[i] += dp[i-coin[j]]
int main()
{
	scanf("%d %d", &N, &S);
	for (int i = 1; i <= N; i++) scanf("%d", coin + i);

	D[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = coin[i]; j <= S; j++)
		{
			D[j] += D[j - coin[i]];
		}
	}
	printf("%d", D[S]);
	return 0;
}