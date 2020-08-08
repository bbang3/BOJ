#include <bits/stdc++.h>
using namespace std;
// O(MlogN)
const int MN = 5e4 + 5;
vector<int> graph[MN];
int parent[MN], depth[MN];
int N;

void dfs(int cur, int prev)
{
	for (int next : graph[cur])
	{
		if (next == prev) continue;
		parent[next] = cur;
		depth[next] = depth[cur] + 1;
		dfs(next, cur);
	}
}

int main()
{
	scanf("%d", &N);
	int a, b;
	for (int i = 1; i <= N - 1; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	depth[1] = 0, parent[1] = -1;
	dfs(1, -1);

	int M;
	scanf("%d", &M);
	while (M--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		while (a != b)
		{
			if (depth[a] >= depth[b]) a = parent[a];
			else b = parent[b];
		}
		printf("%d\n", a);
	}
	return 0;
}