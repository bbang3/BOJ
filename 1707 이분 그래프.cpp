#include <bits/stdc++.h>
using namespace std;

const int MV = 2e5 + 5;

vector<int> graph[MV];
int chk[MV];
int N;

void dfs(int cur, int op) // dfs 방식으로 번갈아가면서 coloring
{
	chk[cur] = op;
	for (int next : graph[cur])
	{
		if (chk[next] == -1)
			dfs(next, !op);
	}
}

int main()
{
	int K;
	scanf("%d", &K);
	while (K--)
	{
		memset(chk, -1, sizeof chk);
		int V, E;
		scanf("%d %d", &V, &E);
		for (int i = 1; i <= V; i++) graph[i].clear();
		for (int i = 1; i <= E; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int v = 1; v <= V; v++)
		{
			if (chk[v] != -1) continue;
			dfs(v, 0);
		}

		bool isBipartite = true;
		for (int v = 1; v <= V; v++)
			for (int next : graph[v])
			{
				if (chk[v] == chk[next]) // 입력으로 주어진 간선에 대해, 간선이 잇는 두 정점의 색이 같은 경우가 있으면 이분 그래프 X
				{
					isBipartite = false;
					break;
				}
			}

		if (isBipartite) puts("YES");
		else puts("NO");
	}
	return 0;
}