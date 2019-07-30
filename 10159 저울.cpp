#include <cstdio>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int N, M;
vector<int> dist[101];
bool haspath[101][101];
queue<int> M;
bool visit[101];

int main()
{
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= M; i++)
	{
		int src, dest;
		scanf("%d%d", &src, &dest);
		dist[src].push_back(dest);
	}

	for (int i = 1; i <= N; i++)
	{
		memset(visit, 0, sizeof(visit));
		M.push(i);
		while (!M.empty())
		{
			int cur = M.front();
			M.pop();
			visit[cur] = true;
			for (int next : dist[cur])
			{
				if (!visit[next])
				{
					haspath[i][next] = true;
					haspath[next][i] = true;
					M.push(next);
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