#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

const int MN = 1e4 + 5;
const int INF = 2e9;

struct P
{
	int v, w;
};

int V, E, S;
vector<P> G[MN];
int dist[MN];

void bfs()
{
	queue<P> Q;
	Q.push({ S, 0 });
	dist[S] = 0;

	while (!Q.empty())
	{
		P cur = Q.front();
		Q.pop();
		if (dist[cur.v] != cur.w) continue;

		for (P next : G[cur.v])
		{
			if (dist[cur.v] + next.w < dist[next.v])
			{
				dist[next.v] = dist[cur.v] + next.w;
				Q.push({ next.v, dist[next.v] });
			}
		}
	}

}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d", &V, &E, &S);
		for (int i = 1; i <= V; i++)
			dist[i] = INF, G[i].clear();

		int a, b, s;
		for (int i = 1; i <= E; i++)
		{
			scanf("%d %d %d", &a, &b, &s);
			G[b].push_back({ a, s });
		}
		bfs();
		int hackcnt = 0, maxt = 0;
		for (int i = 1; i <= V; i++)
		{
			if (dist[i] != INF)
				hackcnt++, maxt = max(maxt, dist[i]);
		}
		printf("%d %d\n", hackcnt, maxt);
	}
	return 0;
}