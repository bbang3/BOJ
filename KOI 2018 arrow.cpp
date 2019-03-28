#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int N;
vector<int> P[100000 + 5];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int pos, color;
		scanf("%d %d", &pos, &color);
		P[color].push_back(pos);
	}
	for (int i = 1; i <= N; i++)
	{
		sort(P[i].begin(), P[i].end());
	}

	long long ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (P[i].size() <= 1) continue;
		for (int j = 0; j < P[i].size(); j++)
		{
			if (j == 0) ans += abs(P[i][j] - P[i][j + 1]);
			else if (j == P[i].size() - 1) ans += abs(P[i][j] - P[i][j - 1]);
			else ans += min(abs(P[i][j] - P[i][j - 1]), abs(P[i][j] - P[i][j + 1]));
		}
	}
	printf("%lld", ans);
	return 0;
}