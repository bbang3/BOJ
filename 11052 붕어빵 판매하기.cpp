#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int arr[1001];
int dp[1001];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);

	
	dp[1] = arr[1];
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		}
	}
	printf("%d", dp[N]);
	return 0;
}