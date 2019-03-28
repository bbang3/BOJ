#include <cstdio>
#include <math.h>
int N;
long long D[10]; // D[i] : i번째 자리 수까지 총합
int main()
{
	scanf("%d", &N);

	int len = (int)log10(N);
	D[1] = 9;
	for (int i = 1; i <= len; i++)
	{
		D[i] = D[i - 1] + 9 * (long long)pow(10, i - 1) * i;
	}
	long long ans = D[len];
	ans += (N - (int)pow(10, len) + 1) * (len + 1);
	printf("%lld", ans);
	return 0;
}