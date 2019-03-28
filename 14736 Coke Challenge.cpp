#include <cstdio>
#include <algorithm>
using namespace std;
#define MOD 1000000007

int ti[1005];
int si[1005];
int end[1005];
int main()
{
	int N, K, A;
	scanf("%d %d %d", &N, &K, &A);
	for (int i = 1; i <= N; i++) scanf("%d %d", ti + i, si + i);
	
	int ans = 0x7fffffff;
	for (int i = 1; i <= N; i++)
	{
		int t = 0, sum = 0;
		while (1)
		{
			if ((K - sum) <= ti[i] * A)
			{
				t += (K - sum) / A;
				break;
			}
			sum += ti[i] * A;
			t += ti[i];
			if (sum == K) break;
			t += si[i];
		}
		ans = min(ans, t);
	}
	printf("%d", ans);

	return 0;
}