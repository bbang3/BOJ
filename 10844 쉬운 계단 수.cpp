#include <stdio.h>
#define MOD 1000000000
int n;
long long arr[10][101];
int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= 9; i++) arr[i][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0) arr[j][i] = arr[j + 1][i - 1] % MOD;
			else if (j == 9) arr[j][i] = arr[j - 1][i - 1] % MOD;
			else arr[j][i] = (arr[j - 1][i - 1] + arr[j + 1][i - 1]) % MOD;
		}
	}

	int result = 0;
	for (int i = 0; i <= 9; i++) result += arr[i][n] % MOD;
	printf("%d", result);
	return 0;
}