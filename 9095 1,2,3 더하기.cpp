#include <cstdio>
#include <memory.h>
#include <algorithm>
int D[15] = { 0,1,2,4, };// dp[i] : i를 1,2,3으로 만드는 경우의 수
						  // dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 4; i <= 15; i++) D[i] = D[i - 1] + D[i - 2] + D[i - 3];
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", D[n]);
	}
	return 0;
}