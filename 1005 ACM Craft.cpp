#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

const int MN = 1000 + 5;
int T, N, K, W;
int time[MN];
int graph[MN][MN];
int dp[MN];
int ind[MN];
queue<int> Q;

void bfs()
{
	for (int i = 1; i <= N; i++)
		if (ind[i] == 0) Q.push(i); // indegree가 0인(들어오는 간선X)인 정점 push
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (graph[cur][i])
			{
				dp[i] = max(dp[i], time[i] + dp[cur]); // 연결된 정점 update
				ind[i]--;
				if (ind[i] == 0) Q.push(i); // cur삭제 후 indegree 0이면 push
			}
		}
	}
}


int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &N, &K);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", time + i);
			dp[i] = time[i];
		}
		for (int i = 1; i <= N; i++)
		{
			ind[i] = 0;
			for (int j = 1; j <= N; j++)
				graph[i][j] = 0;
		}
		for (int i = 0; i < K; i++)
		{
			int src, dest;
			scanf("%d %d", &src, &dest);
			graph[src][dest] = 1;
			ind[dest]++; // indegree 계산
		}
		scanf("%d", &W);
		bfs();
		printf("%d\n", dp[W]);
	}
	return 0;
}