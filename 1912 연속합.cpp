#include <cstdio>
#define MAXN 100000
int arr[MAXN + 1];
int D[MAXN + 1]; // dp[i] = i번째 요소를 마지막 요소로 하는 최대 연속합
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);


	int ans;
	int sum = 0;

	 
	ans = sum = D[1] = arr[1];
	for (int i = 2; i <= N; i++)
	{
		//if (sum < 0)
		//	sum = arr[i];
		//else
		//{
		//	sum += arr[i];
		//}
		//ans = sum > ans ? sum : ans;


		if (D[i - 1] < 0)
		{
			D[i] = arr[i];
		}
		else D[i] = D[i - 1] + arr[i];

		ans = D[i] > ans ? D[i] : ans;
	}
	printf("%d", ans);
	return 0;
}