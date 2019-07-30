#include <stdio.h>

int G[105][105];
int N, M;
bool visit[105];
int cnt = 0;

void dfs(int cur)
{
	visit[cur] = true;
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i] && G[cur][i])
		{
			cnt++;
			dfs(i);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		G[a][b] = G[b][a] = 1;
	}
	dfs(1);
	printf("%d", cnt);
	return 0;
}
