#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

const int MN = 500 + 5;
int N, M, S = 0, T = 500;
int C[MN][MN], F[MN][MN];
vector<int> G[MN];
bool visit[MN];

int dfs(int cur, int flow)
{
	//printf("%d ", cur);
	visit[cur] = true;
	if (cur == T)
	{
		return flow;
	}
	for(int next : G[cur])
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
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		int n, to; 
		scanf("%d", &n);
		G[S].push_back(i);
		C[S][i] = 1;
		while (n--)
		{
			scanf("%d", &to);
			to += 200;
			G[i].push_back(to), G[to].push_back(i);
			C[i][to] = 1;
		}
	}
	for (int i = 1 + 200; i <= 200 + M; i++)
		G[i].push_back(T), C[i][T] = 1;
	
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