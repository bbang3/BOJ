#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MN = 1e5 + 5;
int N, M;
vector<int> cost[MN];
int ncnt[MN];
int ans = 0;
pair<int, int> info[MN];
int D[MN];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		cost[a].push_back(b);
		cost[b].push_back(a);
		ncnt[a]++; ncnt[b]++;
	}
	for (int i = 0; i < N; i++)
	{
		info[i].second = i, info[i].first = ncnt[i];
		D[i] = 1;
	}
	sort(info, info + N);
	for (int i = N - 1; i >= 0; i--)
	{
		int idx = info[i].second;
		//printf("%d\n", idx);
		for (int next : cost[idx])
		{
			if(ncnt[next] < ncnt[idx])
				D[next] = max(D[next], D[idx] + 1);
		}
		ans = max(ans, D[idx]);
	}
	D[0];
	printf("%d", ans);
	return 0;
}