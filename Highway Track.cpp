#include <cstdio>
#include <algorithm>
using namespace std;

int oi[500005];
int di[500005];
int vi[500005];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", oi + i);
	for (int i = 1; i <= N; i++) scanf("%d", di + i);
	
	int mv = -987654321, midx;
	for (int i = 1; i <= N; i++)
	{
		vi[i] = oi[i] - di[i];
	}

	long long minv = 0x7fffffff;
	long long sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += vi[i];
		minv = min(sum, minv);
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (minv >= 0) ans++;
		minv -= vi[i];

	}
	printf("%d", ans);
	return 0;
}