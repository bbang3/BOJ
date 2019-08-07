#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

const int MN = 52 + 5;
int E, S = 1, T = 26;
int C[MN][MN], F[MN][MN]; // capacity, flow
vector<int> G[MN];
bool visit[MN];

// A ~ Z : 1~26, a ~ z : 27 ~ 52
char numbering(char c)
{
	if (c >= 'A' && c <= 'Z') return c - 'A' + 1;
	else return c - 'a' + 27;
}

int dfs(int cur, int flow) // 현재 방문중인 노드, 경로 중 최소 잔여유량
{
	visit[cur] = true;
	if (cur == T) return flow;

	int ret = 0;
	for (int next : G[cur])
		if (!visit[next] && C[cur][next] - F[cur][next] > 0)
		{
			int ret = dfs(next, min(flow, C[cur][next] - F[cur][next]));
			if (ret > 0)
			{
				F[cur][next] += ret;
				F[next][cur] -= ret;
				return ret;
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
	while (1)
	{
		memset(visit, false, sizeof(visit));
		int ret = dfs(S, 2e9);
		if (ret == 0) break;
		ans += ret;
	}
	printf("%d", ans);

	return 0;
}