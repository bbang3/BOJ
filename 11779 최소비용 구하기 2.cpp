#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

const int MN = 1000 + 5;
const int MM = 100000 + 5;

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

int N, M, S, E;
vector<edge> G[MN];
vector<int> V;
priority_queue<edge> PQ;
int cost[MN], pre[MN];
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		int src, dest, w;
		scanf("%d %d %d", &src, &dest, &w);
		G[src].push_back(edge(dest, w));
	}
	scanf("%d %d", &S, &E);

	for (int i = 1; i <= N; i++) cost[i] = INF, pre[i] = -1;
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
				pre[next.v] = cur.v;
				PQ.push(edge(next.v, cost[next.v]));
			}
		}
	}

	printf("%d\n", cost[E]);
	for (int i = E; pre[i] != -1; i = pre[i])
		V.push_back(i);
	V.push_back(S);
	printf("%d\n", V.size());
	for (int i = V.size() - 1; i >= 0; i--)
		printf("%d ", V[i]);
	
	return 0;
}