#include <stdio.h>
#include <vector>
#include <memory.h>
#include <queue>
#define MAXN 1000
using namespace std;

vector<int> dist[MAXN + 5];
bool can[MAXN + 5][MAXN + 5];
int dist[MAXN + 5];
int N, M;
queue<int> M;

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		dist[a].push_back(b);
		dist[b].push_back(a);
	}

	int minkev = 987654321, minv = 0;
	for (int v = 1; v <= N; v++)
	{
		for (int i = 1; i <= N; i++) dist[i] = -1;
		M.push(v);
		dist[v] = 0;

		while (!M.empty())
		{
			int cur = M.front();
			M.pop();

			for (int next : dist[cur])
			{
				if (dist[next] == -1 || dist[cur] + 1 < dist[next])
				{
					dist[next] = dist[cur] + 1;
					M.push(next);
				}
			}

		}

		int sum = 0;
		for (int i = 1; i <= N; i++)
		{
			//if (v == i) continue;
			sum += dist[i];
		}
		if (sum < minkev)
		{
			minkev = sum;
			minv = v;
		}
	}
	printf("%d", minv);

	return 0;
}