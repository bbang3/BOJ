#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MN = 1e5 + 5;


struct edge
{
	int v;
	ll w;

	edge() {}
	edge(int v, ll w) : v(v), w(w) {}
};

bool operator < (const edge a, const edge b)
{
	return a.w > b.w;
}
vector<edge> G[MN];
ll dist[MN];
int no[MN];
priority_queue<edge> PQ;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &no[i]);
	no[N - 1] = 0;
	for (int i = 1; i <= M; i++)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		G[a].push_back({ b,w, });
		G[b].push_back({ a,w, });
	}

	for (int i = 0; i < N; i++) dist[i] = LLONG_MAX;
	PQ.push({ 0, 0 });
	dist[0] = 0;
	while (!PQ.empty())
	{
		edge cur = PQ.top(); PQ.pop();
		if (cur.w != dist[cur.v]) continue;
		for (auto next : G[cur.v])
		{
			if (!no[next.v] && dist[next.v] > dist[cur.v] + next.w)
			{
				dist[next.v] = dist[cur.v] + next.w;
				PQ.push({ next.v, dist[next.v] });
			}
		}
	}
	printf("%lld", dist[N - 1] == LLONG_MAX ? -1 : dist[N - 1]);

	return 0;
}