#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
int arr[1001];
int dp[1001]; // dp[i] = i번째 요소부터 시작하는 LIS
int N;
int f(int start) {
	if (dp[start] != -1) return dp[start];
	dp[start] = 1;
	for (int i = start + 1; i <= N; i++) {
		if (arr[i] > arr[start])
			dp[start] = max(dp[start], f(i) + 1);
	}
	return dp[start];
}

int main()
{
	scanf("%d"	, &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	memset(dp, -1, sizeof(dp));
	
	int ans = -1;
	for (int i = 1; i <= N; i++)
		ans = max(ans, f(i));
	printf("%d", ans);
	return 0;
}