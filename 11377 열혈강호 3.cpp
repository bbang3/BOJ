#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

const int MN = 1000;
const int MX = 2 * MN + 5;
int N, M, K;
int S = 0, T = 2 * MN + 1, B = 2 * MN + 2;
int C[MX][MX], F[MX][MX];
vector<int> G[MX];
bool visit[MX];

int dfs(int cur, int flow)
{
	//printf("%d ", cur);
	visit[cur] = true;
	if (cur == T)
	{
		return flow;
	}
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
	scanf("%d %d %d", &N, &M, &K);
	G[S].push_back(B), G[B].push_back(S);
	C[S][B] = K;
	for (int i = 1; i <= N; i++)
	{
		int n, to;
		scanf("%d", &n);
		G[S].push_back(i), G[i].push_back(S), C[S][i] =	1;
		G[B].push_back(i), G[i].push_back(B), C[B][i] = 1;
		while (n--)
		{
			scanf("%d", &to);
			to += MN;
			G[i].push_back(to), G[to].push_back(i);
			C[i][to] = 1;
		}
	}
	for (int i = 1 + MN; i <= MN + M; i++)
		G[i].push_back(T), G[T].push_back(i), C[i][T] = 1;


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