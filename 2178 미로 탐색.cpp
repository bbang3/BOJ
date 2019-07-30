#include <stdio.h>
#include <vector>
#include <memory.h>
#include <queue>
#define MAXN 100
using namespace std;
typedef pair<int, int> pii;
int candy[MAXN + 5][MAXN + 5];
int dist[MAXN + 5][MAXN + 5];
int N, M;
queue<pii> M;

bool safe(int i, int j)
{
	return i >= 1 && i <= N && j >= 1 && j <= M;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", &candy[i][j]);


	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			dist[i][j] = -1;

	M.push({ 1, 1 });
	dist[1][1] = 1;

	int di[] = { 1,0,-1,0 }, dj[] = { 0,1,0,-1 };

	while (!M.empty())
	{
		pii cur = M.front();
		M.pop();

		int curi = cur.first, curj = cur.second;
		if (curi == N && curj == M) break;
		for (int k = 0; k < 4; k++)
		{
			int ni = curi + di[k], nj = curj + dj[k];

			if (safe(ni, nj) && candy[ni][nj] && dist[ni][nj] == -1)
			{
				dist[ni][nj] = dist[curi][curj] + 1;
				M.push({ ni,nj });
			}
		}
	}

	printf("%d", dist[N][M]);

	return 0;
}