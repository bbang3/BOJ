#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
#define INF LLONG_MAX

const int MN = 100000 + 5;
const int MM = 200000 + 5;

struct edge
{
	int v;
	long long w;

	edge(int v, long long w) : v(v), w(w) {}

	bool operator < (const edge a) const
	{
		return w > a.w;
	}
};

int N, M, D, E;
vector<edge> G[MN];
priority_queue<edge> PQ;
long long D1[MN], D2[MN], H[MN];

void f(int S, long long dist[])
{
	for (int i = 1; i <= N; i++) dist[i] = INF;
	dist[S] = 0;
	PQ.push(edge(S, dist[S]));
	while (!PQ.empty())
	{
		edge cur = PQ.top(); PQ.pop();

		if (dist[cur.v] != cur.w) continue;

		for (edge next : G[cur.v])
		{
			if (H[next.v] > H[cur.v] && dist[cur.v] + next.w < dist[next.v])
			{
				dist[next.v] = dist[cur.v] + next.w;
				PQ.push(edge(next.v, dist[next.v]));
			}
		}
	}
}

int main()
{
	scanf("%d%d%d%d", &N, &M, &D, &E);
	for (int i = 1; i <= N; i++) scanf("%lld", &H[i]);
	for (int i = 1; i <= M; i++)
	{
		int src, dest, w;
		scanf("%d %d %d", &src, &dest, &w);
		G[src].push_back(edge(dest, w));
		G[dest].push_back(edge(src, w));
	}

	f(1, D1);
	f(N, D2);

	//for (int i = 1; i <= N; i++) printf("%lld %lld\n", D1[i], D2[i]);

	long long maxv = LLONG_MIN;
	for (int i = 1; i <= N; i++)
	{
		if (D1[i] == INF || D2[i] == INF) continue;

		maxv = max(maxv, (H[i] * E - (D1[i] + D2[i]) * D));

	}
	if (maxv == LLONG_MIN) puts("Impossible");
	else printf("%lld", maxv);
	return 0;
}