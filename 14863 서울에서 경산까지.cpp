#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 100 + 5;
const int MK = 100000 + 5;
int walk[MN][2], bike[MN][2]; // 0 : time, 1 : money
int dp[MN][MK]; // dp[i][j] : i번째 도시까지 여행했을 때, j분을 써서 여행하는 최소 모금액
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++)
	{
		int wt, wm, bt, bm;
		scanf("%d %d %d %d", &wt, &wm, &bt, &bm);
		walk[i][0] = wt, walk[i][1] = wm;
		bike[i][0] = bt, bike[i][1] = bm;
	}

	dp[1][walk[1][0]] = walk[1][1];
	dp[1][bike[1][0]] = max(dp[1][bike[1][0]], bike[1][1]);

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (!dp[i - 1][j]) continue;

			if (j + walk[i][0] <= K)
				dp[i][j + walk[i][0]] = max(dp[i][j + walk[i][0]], dp[i - 1][j] + walk[i][1]);
			if (j + bike[i][0] <= K)
				dp[i][j + bike[i][0]] = max(dp[i][j + bike[i][0]], dp[i - 1][j] + bike[i][1]);
		}
	}

	int ans = 0;
	for (int j = 1; j <= K; j++)
		ans = max(ans, dp[N][j]);
	printf("%d", ans);
	return 0;
}