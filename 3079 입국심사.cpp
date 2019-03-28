#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;

const int MN = 100000;
int N, M;
int time[MN + 5];
int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		scanf("%d", time + i);

	// parametric search에서 right를 어떻게 잡아야 하는가?
	long long left = 0, right = 1000000000000000000LL, mid, ans = LLONG_MAX;
	while (left <= right)
	{
		mid = (left + right) / 2;

		long long cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			cnt += mid / time[i];
		}

		if (cnt < M)
			left = mid + 1;
		else
		{
			right = mid - 1;
			ans = min(ans, mid);
		}
	}
	printf("%lld", ans);
	return 0;
}