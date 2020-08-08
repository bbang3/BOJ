#include <cstdio>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef long long ll;
const int MN = 100000;
int N, M;
int time[MN + 5];
int main()
{
	scanf("%d %d", &N, &M);

	int mx = -1;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", time + i);
		mx = max(mx, time[i]);
	}
	// parametric search에서 right를 어떻게 잡아야 하는가?
	ll left = 0, right = (ll)mx * M, mid, ans = LLONG_MAX;
	while (left <= right)
	{
		mid = (left + right) / 2;

		long long cnt = 0;
		for (int i = 1; i <= N; i++)
			cnt += mid / time[i];

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