#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;
#define INF LLONG_MAX

const int MN = 4000 + 5;
const int MM = 100000 + 5;

struct edge
{
	int v;
	long long w;
	bool run; // 1이면 해당 정점을 달려서 온 상태

	edge(int v, long long w) : v(v), w(w) {}
	edge(int v, long long w, bool run) : v(v), w(w), run(run) {}

	bool operator < (const edge a) const
	{
		return w > a.w;
	}
};

int N, M, S;
vector<edge> G[MN];
priority_queue<edge> PQ;
long long dist[MN], dist2[2][MN]; 
// dist2[0][i] : 마지막 이동을 느리게 해서 i번 정점으로 가는 최단 경로
// dist2][1][i] : 마지막 이동을 빠르게 해서 i번 정점으로 가는 최단 경로

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		int src, dest, w;
		scanf("%d %d %d", &src, &dest, &w);
		w *= 2;
		G[src].push_back(edge(dest, w));
		G[dest].push_back(edge(src, w)); 
	}

	for (int i = 1; i <= N; i++) dist[i] = INF;
	S = 1;
	dist[S] = 0;
	PQ.push(edge(S, dist[S]));
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

	for (int i = 1; i <= N; i++) dist2[0][i] = dist2[1][i] = INF;
	dist2[0][S] = 0;
	PQ.push(edge(S, 0, false));

	while (!PQ.empty())
	{
		edge cur = PQ.top(); PQ.pop();

		if (dist2[cur.run][cur.v] != cur.w) continue;

		for (edge next : G[cur.v])
		{
			int w = cur.run ? next.w * 2 : next.w / 2;
			if (dist2[cur.run][cur.v] + w < dist2[!cur.run][next.v])
			{
				dist2[!cur.run][next.v] = dist2[cur.run][cur.v] + w;
				PQ.push(edge(next.v, dist2[!cur.run][next.v], !cur.run));
			}
		}
		//for (int i = 1; i <= N; i++) printf("%2d ", dist2[0][i] == INF ? -1 : dist2[0][i]); puts("");
		//for (int i = 1; i <= N; i++) printf("%2d ", dist2[1][i] == INF ? -1 : dist2[1][i]); puts("");
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		//printf("%lld %lld %lld\n", dist[i], dist2[0][i], dist2[1][i]);
		if (dist[i] < min(dist2[0][i],dist2[1][i])) ans++;
	}
	printf("%d", ans);
	return 0;
}