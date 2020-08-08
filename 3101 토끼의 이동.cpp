#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char mv[300000 + 5];
int main()
{
	ll N, K;
	scanf("%lld %lld", &N, &K);
	scanf("%s", mv + 1);

	ll sum = 1;
	ll y = 1, x = 1;
	for (int i = 1; i <= K; i++)
	{
		if (mv[i] == 'U') y--;
		else if (mv[i] == 'D') y++;
		else if (mv[i] == 'L') x--;
		else x++;

		ll group = x + y - 1, num = 0;
		if (group <= N)
		{
			num += (group - 1) * group / 2;

			if (group % 2 == 1) num += x;
			else num += y;
		}
		else
		{
			num += N * (N + 1) / 2;
			ll groupFromBack = 2 * N - group;
			num += (N - 1) * N / 2 - (groupFromBack * (groupFromBack + 1) / 2);

			if (group % 2 == 1) num += N - y + 1;
			else num += N - x + 1;
		}

		sum += num;
	}
	printf("%lld", sum);

	return 0;
}