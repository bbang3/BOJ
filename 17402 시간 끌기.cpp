#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;

const int MN = 200;
const int MX = 2 * MN + 5;
int map[MX][MX];
int C[MX][MX], F[MX][MX];
int level[MX], work[MX];
vector<int> G[MX];
const int S = 0, E = 2 * MN + 3;
int N, M, K;

bool bfs()
{
	fill(level, level + MX, -1);
	queue<int> Q;
	level[S] = 0;
	Q.push(S);
	while (!Q.empty())
	{
		int cur = Q.front(); Q.pop();
		for (int next : G[cur])
		{
			if (level[next] == -1 && C[cur][next] - F[cur][next] > 0)
			{
				level[next] = level[cur] + 1;
				Q.push(next);
			}
		}
	}
	return level[E] != -1;
}

int dfs(int cur, int flow)
{
	if (cur == E) return flow;
	for (int& i = work[cur]; i < G[cur].size(); i++)
	{
		int next = G[cur][i];
		if (level[next] == level[cur] + 1 && C[cur][next] - F[cur][next] > 0)
		{
			int ret = dfs(next, min(flow, C[cur][next] - F[cur][next]));
			if (ret > 0)
			{
				F[cur][next] += ret;
				F[next][cur] -= ret;
				return ret;
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) G[S].push_back(i), C[S][i] = 1;
	for (int i = 1 + MN; i <= M + MN; i++) G[i].push_back(E), C[i][E] = 1;
	for (int i = 1; i <= K; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		G[x].push_back(MN + y), G[MN + y].push_back(x);
		C[x][MN + y] = 1;
	}

	int ans = 0;
	while (bfs())
	{
		fill(work, work + MX, 0);
		int ret = dfs(S, 2e9);
		if (ret == 0) break;
		ans++;
	}
	printf("%d", M + N - ans);

	return 0;
}