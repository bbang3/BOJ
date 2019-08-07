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
int cost[MN];

int main()
{
	scanf("%d%d%d", &N, &M, &S);
	for (int i = 1; i <= M; i++)
	{
		int src, dest, w;
		scanf("%d %d %d", &src, &dest, &w);
		G[src].push_back(edge(dest, w));
	}

	for (int i = 1; i <= N; i++) cost[i] = INF;
	cost[S] = 0; 
	PQ.push(edge(S, cost[S])); 
	while (!PQ.empty())
	{
		edge cur = PQ.top(); PQ.pop();

		if (cost[cur.v] != cur.w) continue;

		for (edge next : G[cur.v])
		{
			if (cost[cur.v] + next.w < cost[next.v])
			{
				cost[next.v] = cost[cur.v] + next.w;
				PQ.push(edge(next.v, cost[next.v]));
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (cost[i] == INF) puts("INF");
		else printf("%d\n", cost[i]);
	}
	return 0;
}