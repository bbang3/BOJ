#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 5;
int to[100001];
bool visited[MN], finished[MN];
int ans;

void dfs(int n)
{
	visited[n] = true;
	int next = to[n];
	if (visited[next] && !finished[next]) // back edge
	{
		ans--;
		for (int i = next; i != n; i = to[i]) 
			ans--;
	}
	if(!visited[next]) dfs(next);

	finished[n] = true;
}



int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) scanf("%d", &to[i]);

		ans = N;
		memset(visited, false, sizeof(visited));
		memset(finished, false, sizeof(finished));

		for (int j = 1; j <= N; j++)
			if (!visited[j]) dfs(j);

		printf("%d\n", ans);
	}
	return 0;
}