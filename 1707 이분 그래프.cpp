#include <bits/stdc++.h>
using namespace std;

const int MV = 2e5 + 5;

vector<int> graph[MV];
int chk[MV];
int N;

void dfs(int cur, int op) // dfs ������� �����ư��鼭 coloring
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
				if (chk[v] == chk[next]) // �Է����� �־��� ������ ����, ������ �մ� �� ������ ���� ���� ��찡 ������ �̺� �׷��� X
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