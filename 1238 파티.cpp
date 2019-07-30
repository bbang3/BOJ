#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

#define INF 987654321
const int MN = 1e3 + 5;
const int MM = 1e4 + 5;

struct edge
{
	int v;
	int w;

	edge(int v, int w) : v(v), w(w) {}

	bool operator < (const edge a) const
	{
		return w > a.w;
	}
};

int N, M, X;
vector<edge> G[MN];
vector<edge> RG[MN]; // 방향 반대인 그래프
priority_queue<edge> PQ;
int dist[MN], dist2[MN];

int main()
{
	scanf("%d %d %d", &N, &M, &X);
	for (int i = 1; i <= M; i++)
	{
		int src, dest, w;
		scanf("%d %d %d", &src, &dest, &w);
		G[src].push_back(edge(dest, w));
		RG[dest].push_back(edge(src, w));
	}

	for (int i = 1; i <= N; i++) dist[i] = INF;
	dist[X] = 0;
	PQ.push(edge(X, dist[X]));
	while (!PQ.empty())
	{
		edge cur = PQ.top(); PQ.pop();

		if (dist[cur.v] != cur.w) continue;

		for (edge next : G[cur.v])
		{
			if (dist[cur.v] + next.w < dist[next.v])
			{
				dist[next.v] = dist[cur.v] + next.w;
				PQ.push(edge(next.v, dist[next.v]));
			}
		}
	}

	for (int i = 1; i <= N; i++) dist2[i] = INF;
	dist2[X] = 0;
	PQ.push(edge(X, dist2[X]));
	while (!PQ.empty())
	{
		edge cur = PQ.top(); PQ.pop();

		if (dist2[cur.v] != cur.w) continue;

		for (edge next : RG[cur.v])
		{
			if (dist2[cur.v] + next.w < dist2[next.v])
			{
				dist2[next.v] = dist2[cur.v] + next.w;
				PQ.push(edge(next.v, dist2[next.v]));
			}
		}
	}

	int ans = -1;
	for (int i = 1; i <= N; i++)
	{
		ans = max(ans, dist[i] + dist2[i]);
	}
	printf("%d", ans);

	return 0;
}