#include <cstdio>
using namespace std;


//dp[i][j] : (0,0)부터 (i,j)까지의 배열의 숫자의 합
int arr[301][301];
int dp[301][301];
int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &arr[i][j]);
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}
	int K, i, j, x, y;
	scanf("%d", &K);
	while (K--)
	{
		scanf("%d%d%d%d", &i, &j, &x, &y);
		printf("%d\n", dp[x][y] - dp[x][j-1] - dp[i-1][y] + dp[i-1][j-1]);
	}
	return 0;
}