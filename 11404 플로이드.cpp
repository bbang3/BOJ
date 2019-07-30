#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 987654321
int N, M;
int dist[100 + 5][100 + 5];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	for (int i = 1; i <= M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}

	for (int i = 1; i <= N; i++, puts(""))
		for (int j = 1; j <= N; j++)
			printf("%d ", dist[i][j] == INF ? 0 : dist[i][j]);
	return 0;
}