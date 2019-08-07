#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MN = 100;
const int MX = MN * 2 + 5;

int N, M, S = 0, T = MN * 2 + 1;
int C[MX][MX], F[MX][MX], cost[MX][MX];
int pre[MX], dist[MX], inQ[MX];
vector<int> G[MX];
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = MN + 1; i <= MN + N; i++)
	{
		int n;
		scanf("%d", &C[i][T]);
		G[i].push_back(T);
	}
	for (int i = 1; i <= M; i++)
	{
		int n;
		scanf("%d", &C[S][i]);
		G[S].push_back(i);
		for (int j = MN + 1; j <= MN + N; j++)
		{
			G[i].push_back(j), G[j].push_back(i);
			C[i][j] = 2e9;
		}
	}
	for (int i = 1; i <= M; i++) // 서점
		for (int j = MN + 1; j <= MN + N; j++) // 사람
		{
			scanf("%d", &cost[i][j]);
			cost[j][i] = -cost[i][j];
		}

	int ans = 0;
	while (1)
	{
		queue<int> Q;
		fill(dist, dist + MX, 2e9);
		fill(pre, pre + MX, -1);
		fill(inQ, inQ + MX, false);
		Q.push(S), dist[S] = 0, inQ[S] = true;
		while (!Q.empty())
		{
			int cur = Q.front(); Q.pop();
			inQ[cur] = false;
			for (int next : G[cur])
			{
				if (C[cur][next] - F[cur][next] > 0
					&& dist[cur] + cost[cur][next] < dist[next])
				{
					dist[next] = dist[cur] + cost[cur][next];
					pre[next] = cur;
					if (!inQ[next])
					{
						Q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		if (pre[T] == -1) break;
		int flow = 2e9;
		for (int i = T; i != S; i = pre[i])
			flow = min(flow, C[pre[i]][i] - F[pre[i]][i]);
		for (int i = T; i != S; i = pre[i])
		{
			ans += flow * cost[pre[i]][i];
			F[pre[i]][i] += flow, F[i][pre[i]] -= flow;
		}
	}
	printf("%d", ans);


	return 0;
}