#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;

const int MN = 52 + 5;
int E, S = 1, T = 26;
int C[MN][MN], F[MN][MN], level[MN], work[MN]; // capacity, flow
vector<int> G[MN];
bool visit[MN];

// A ~ Z : 1~26, a ~ z : 27 ~ 52
char numbering(char c)
{
	if (c >= 'A' && c <= 'Z') return c - 'A' + 1;
	else return c - 'a' + 27;
}

bool bfs() // 증가 경로가 남아있으면 true
{
	memset(level, -1, sizeof(level));
	level[S] = 0;
	queue<int> Q;
	Q.push(S);

	while (!Q.empty())
	{
		int cur = Q.front(); Q.pop();
		for (int next : G[cur])
			if (level[next] == -1 && C[cur][next] - F[cur][next] > 0)
			{
				level[next] = level[cur] + 1;
				Q.push(next);
			}
	}
	return level[T] != -1;
}

int dfs(int cur, int flow) // 현재 방문중인 노드, 경로 중 최소 잔여유량
{
	if (cur == T) return flow;

	int ret = 0;
	for (int &i = work[cur]; i < G[cur].size(); i++)
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
	scanf("%d", &E);

	for (int i = 1; i <= E; i++)
	{
		char a, b; int cap;
		scanf(" %c %c %d", &a, &b, &cap);
		a = numbering(a), b = numbering(b);
		if (!C[a][b]) G[a].push_back(b), G[b].push_back(a);
		C[a][b] += cap, C[b][a] += cap;
	}

	int ans = 0;
	while (bfs())
	{
		memset(work, 0, sizeof(work));
		while (1)
		{
			int ret = dfs(S, 2e9);
			if (ret == 0) break;
			ans += ret;
		}
	}
	printf("%d", ans);

	return 0;
}