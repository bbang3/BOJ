#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MX = 1e5 + 5;
bool isprime[MX];
vector<int> P;

int f(int cur, int target)
{
	int ret = abs(cur - target);
	if (cur >= target) ret = min(ret, f(cur / 2, target) + 1);
	if (cur >= target) ret = min(ret, f(cur / 3, target) + 1);

	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);

	fill(isprime, isprime + MX, true);
	for (int i = 2; i * i <= 100000; i++)
		if (isprime[i])
			for (int j = i * i; j <= 100000; j += i)
				isprime[j] = false;
	for (int i = 2; i <= 100000; i++)
		if (isprime[i]) P.push_back(i);

	while (T--)
	{
		int N, A, B;
		scanf("%d %d %d", &N, &A, &B);
		int idx = lower_bound(P.begin(), P.end(), A) - P.begin();
		if (idx >= P.size() || P[idx] > B)
		{
			puts("-1");
			continue;
		}
		int ans = 2e9;
		for (int i = idx; i < P.size() && P[i] <= B; i++)
			ans = min(ans, f(N, P[i]));
		printf("%d\n", ans);
	}
	return 0;
}