#include <cstdio>
#include <algorithm>
using namespace std;
int score[10001];
int dp[10001][2];

int N;
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &score[i]);

	dp[1][0] = dp[1][1] = score[1];
	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = dp[i - 1][1] + score[i];
		dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + score[i];
	}
	printf("%d", dp[N][0] > dp[N][1] ? dp[N][0] : dp[N][1]);
	return 0;
}