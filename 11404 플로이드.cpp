#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 987654321
int N, M;
int cost[100 + 5][100 + 5];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (i == j) cost[i][j] = 0;
			else cost[i][j] = INF;
		}
	for (int i = 1; i <= M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		cost[a][b] = min(cost[a][b], c);
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}

	for (int i = 1; i <= N; i++, puts(""))
		for (int j = 1; j <= N; j++)
			printf("%d ", cost[i][j] == INF ? 0 : cost[i][j]);
	return 0;
}