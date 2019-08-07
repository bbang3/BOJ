#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

const int MN = 50;
const int MX = 50 * 2 + 5;
int N, S = 0, T = MN * 2 + 1;
int shark[MN + 5][3];
int C[MX][MX], F[MX][MX];
bool visit[MX];
vector<int> G[MX];

bool eat(int i, int j)
{
	return shark[i][0] >= shark[j][0] && shark[i][1] >= shark[j][1] && shark[i][2] >= shark[j][2];
}

int dfs(int cur, int flow)
{
	visit[cur] = true;
	if (cur == T) return flow;
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
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d %d", &shark[i][0], &shark[i][1], &shark[i][2]);

	for (int i = 1; i <= N; i++)
	{
		G[S].push_back(i);
		C[S][i] = 2;
		G[i + MN].push_back(T);
		C[i + MN][T] = 1;
		for (int j = i + 1; j <= N; j++)
		{
			if (eat(i, j))
			{
				G[i].push_back(j + MN);
				G[j + MN].push_back(i);
				C[i][j + MN] = 1;
			}
			else if (eat(j, i))
			{
				G[j].push_back(i + MN);
				G[i + MN].push_back(j);
				C[j][i + MN] = 1;
			}
		}
	}

	int ans = 0;
	while (1)
	{
		memset(visit, 0, sizeof(visit));
		int ret = dfs(S, 2e9);
		if (ret == 0) break;
		ans += ret;
	}
	printf("%d", N - ans);
	return 0;
}