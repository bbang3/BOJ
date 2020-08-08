#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
// 친구가 있는 곳으로 가는 경로 길이 총합(중복 제외) - 가장 먼 친구 경로 길이
struct edge
{
	int v;
	int w;
	edge(int dest, int w) : v(dest), w(w) {}
};

const int MN = 1e5 + 5;

vector<edge> graph[MN];
int N, F;
int friends[MN];
int totallen = 0, maxlen = 0;

bool dfs(int cur, int prev, int w)
{
	bool ret = false;
	if (friends[cur]) totallen += w, ret = true;

	for (edge next : graph[cur])
	{
		if (ret) w = 0;
		if (next.v != prev)
		{
			ret |= dfs(next.v, cur, w + next.w);
		}
	}

	return ret;
}

void get_maxlen(int cur, int prev, int w)
{
	if (friends[cur]) maxlen = max(maxlen, w);

	for (edge next : graph[cur])
		if (next.v != prev)
			get_maxlen(next.v, cur, w + next.w);
}

int main()
{
	scanf("%d %d", &N, &F);

	for (int i = 0; i < N - 1; i++)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		graph[a].push_back(edge(b, w));
	}
	for (int i = 0; i < F; i++)
	{
		int a;
		scanf("%d", &a);
		friends[a] = 1;
	}
	dfs(1, -1, 0);
	get_maxlen(1, -1, 0);
	printf("%d", totallen - maxlen);
}