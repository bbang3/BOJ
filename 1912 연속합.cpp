#include <cstdio>
#define MAX 100000
int arr[MAX + 1];
int dp[MAX + 1]; // dp[i] = i��° ��Ҹ� ������ ��ҷ� �ϴ� �ִ� ������
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);


	int ans;
	int sum = 0;

	/* 
	ans = sum = dp[1] = arr[1];
	for (int i = 2; i <= N; i++)
	{
		if (sum < 0)
			sum = arr[i];
		else
		{
			sum += arr[i];
		}
		ans = sum > ans ? sum : ans;

	*/
	/* dp ���
		if (dp[i - 1] < 0)
		{
			dp[i] = arr[i];
		}
		else dp[i] = dp[i-1] + arr[i];

		ans = dp[i] > ans ? dp[i] : ans;
	*/
	printf("%d", ans);
	return 0;
}