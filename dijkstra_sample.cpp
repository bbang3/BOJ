#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

const int MN = 20000 + 5;
const int MM = 300000 + 5;

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

int N, M, S;
vector<edge> G[MN];
priority_queue<edge> PQ;
int dist[MN];

int main()
{
	scanf("%d%d%d", &N, &M, &S);
	for (int i = 1; i <= M; i++)
	{
		int src, dest, w;
		scanf("%d %d %d", &src, &dest, &w);
		G[src].push_back(edge(dest, w));
	}

	for (int i = 1; i <= N; i++) dist[i] = INF;
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

	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == INF) puts("INF");
		else printf("%d\n", dist[i]);
	}
	return 0;
}