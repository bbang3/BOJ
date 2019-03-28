#include <cstdio>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int N, M;
vector<int> graph[101];
bool haspath[101][101];
queue<int> Q;
bool visited[101];

int main()
{
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= M; i++)
	{
		int src, dest;
		scanf("%d%d", &src, &dest);
		graph[src].push_back(dest);
	}

	for (int i = 1; i <= N; i++)
	{
		memset(visited, 0, sizeof(visited));
		Q.push(i);
		while (!Q.empty())
		{
			int cur = Q.front();
			Q.pop();
			visited[cur] = true;
			for (int next : graph[cur])
			{
				if (!visited[next])
				{
					haspath[i][next] = true;
					haspath[next][i] = true;
					Q.push(next);
				}
			}
		}

	}

	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (haspath[i][j]) cnt++;
		}
		printf("%d\n", N - cnt - 1);
	}
	return 0;
}