#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
int N, M;
int G[505][505];
int RG[505][505];
bool visit[505];
int cnt1 = 0, cnt2 = 0;

void dfs(int cur)
{
	visit[cur] = true;

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i] && G[cur][i])
		{
			cnt1++;
			dfs(i);
		}
	}
}

void dfs2(int cur)
{
	visit[cur] = true;

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i] && RG[cur][i])
		{
			cnt2++;
			dfs2(i);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		int src, dest;
		scanf("%d %d", &src, &dest);
		G[src][dest] = 1;
		RG[dest][src] = 1;
	}
	
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		cnt1 = cnt2 = 0;
		memset(visit, false, sizeof(visit));
		dfs(i);
		memset(visit, false, sizeof(visit));
		dfs2(i);
		if (cnt1 + cnt2 == N - 1) ans++;
	}

	printf("%d", ans);

	return 0;
}