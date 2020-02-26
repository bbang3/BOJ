#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
	int i, j, k;
};

const int MN = 1000 + 5;
int N, M, K;
int dist[MN][MN][15];
char map[MN][MN];
const int di[] = { 1,0,-1,0 }, dj[] = { 0,1,0,-1 };
queue<node> Q;

bool safe(int i, int j) { return i >= 1 && i <= N && j >= 1 && j <= M; }

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) scanf("%s", map[i] + 1);

	fill(&dist[0][0][0], &dist[0][0][0] + MN * MN * 15, 1e9);
	dist[1][1][0] = 1;
	Q.push({ 1, 1, 0 });

	while (!Q.empty())
	{
		node cur = Q.front(); Q.pop();
		if (cur.i == N && cur.j == M) break;

		for (int k = 0; k < 4; k++)
		{
			int ni = cur.i + di[k], nj = cur.j + dj[k];
			if (!safe(ni, nj)) continue;
			if (map[ni][nj] == '1')
			{
				if (cur.k < K && dist[ni][nj][cur.k + 1] > dist[cur.i][cur.j][cur.k] + 1)
				{
					dist[ni][nj][cur.k + 1] = dist[cur.i][cur.j][cur.k] + 1;
					Q.push({ ni, nj, cur.k + 1 });
				}
			}
			else if (dist[ni][nj][cur.k] > dist[cur.i][cur.j][cur.k] + 1)
			{
				dist[ni][nj][cur.k] = dist[cur.i][cur.j][cur.k] + 1;
				Q.push({ ni, nj, cur.k });
			}
		}
	}
	int ans = 1e9;
	for (int i = 0; i <= K; i++)
	{
		if (dist[N][M][i] == -1) continue;
		ans = min(ans, dist[N][M][i]);
	}
	printf("%d", ans == 1e9 ? -1 : ans);

	return 0;
}