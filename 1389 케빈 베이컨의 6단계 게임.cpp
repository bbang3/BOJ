#include <stdio.h>
#include <vector>
#include <memory.h>
#include <queue>
#define MAXN 1000
using namespace std;

vector<int> cost[MAXN + 5];
bool can[MAXN + 5][MAXN + 5];
int cost[MAXN + 5];
int N, M;
queue<int> M;

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		cost[a].push_back(b);
		cost[b].push_back(a);
	}

	int minkev = 987654321, minv = 0;
	for (int v = 1; v <= N; v++)
	{
		for (int i = 1; i <= N; i++) cost[i] = -1;
		M.push(v);
		cost[v] = 0;

		while (!M.empty())
		{
			int cur = M.front();
			M.pop();

			for (int next : cost[cur])
			{
				if (cost[next] == -1 || cost[cur] + 1 < cost[next])
				{
					cost[next] = cost[cur] + 1;
					M.push(next);
				}
			}

		}

		int sum = 0;
		for (int i = 1; i <= N; i++)
		{
			//if (v == i) continue;
			sum += cost[i];
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