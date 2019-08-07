#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

const int MN = 500 + 5;
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

int N, M, S, D;
vector<edge> G[MN], RG[MN]; // RG : 방향 반대로
priority_queue<edge> PQ; 
int cost[MN], dist2[MN]; // d1 : S에서 각 정점으로 가는 최단경로, d2 : 각 정점에서 D로 가는 최단경로

void f(int S, int dist[], vector<edge> G[])
{
	for (int i = 0; i < N; i++) dist[i] = INF;
	dist[S] = 0;
	PQ.push(edge(S, dist[S]));
	while (!PQ.empty())
	{
		edge cur = PQ.top(); PQ.pop();

		if (dist[cur.v] != cur.w) continue;

		for (edge next : G[cur.v])
		{
			if (next.w == -1) continue;
			if (dist[cur.v] + next.w < dist[next.v])
			{
				dist[next.v] = dist[cur.v] + next.w;
				PQ.push(edge(next.v, dist[next.v]));
			}
		}
	}
}

int main()
{
	while (1)
	{
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0) return 0;
		scanf("%d %d", &S, &D);
		for (int i = 0; i < N; i++) G[i].clear(), RG[i].clear();
		for (int i = 1; i <= M; i++)
		{
			int src, dest, w;
			scanf("%d %d %d", &src, &dest, &w);
			G[src].push_back(edge(dest, w));
			RG[dest].push_back(edge(src, w));
		}

		f(S, cost, G);
		f(D, dist2, RG);

		for (int i = 0; i < N; i++)
		{
			for (edge &e : G[i])
			{
				if (cost[i] == INF || dist2[e.v] == INF) continue;

				if (cost[i] + e.w + dist2[e.v] == cost[D])
				{
					e.w = -1;
				}
			}
		}

		f(S, cost, G);
		printf("%d\n", cost[D] == INF ? -1 : cost[D]);
	}
	return 0;
}