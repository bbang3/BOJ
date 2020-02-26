#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
#include <memory.h>
#include <queue>
using namespace std;

const int MN = 200 + 5;

struct pos { int i; int j; int k; };

const int di[] = { -1, -2, -2, -1, 1, 2, 2, 1, 1,0,-1,0 };
const int dj[] = { -2, -1, 1, 2, 2, 1, -1, -2, 0,1,0,-1 };
int W, H, K;
int map[MN][MN];
int dist[MN][MN][30 + 5]; // [i][j][k] : (i, j)에 특수 이동을 K번 써서 도착하는 최단 경로

bool safe(int i, int j) { return i >= 1 && i <= H && j >= 1 && j <= W && map[i][j] == 0; }

int main()
{
	scanf("%d %d %d", &K, &W, &H);
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			scanf("%d", &map[i][j]);

	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			for (int k = 0; k <= K; k++)
				dist[i][j][k] = 2e9;

	queue<pos> Q;
	Q.push({ 1, 1, 0 });
	dist[1][1][0] = 0;
	while (!Q.empty())
	{
		pos cur = Q.front(); Q.pop();

		for (int t = cur.k < K ? 0 : 8; t < 12; t++)
		{
			int ni = cur.i + di[t], nj = cur.j + dj[t], nk = t < 8 ? cur.k + 1 : cur.k;
			if (safe(ni, nj) && dist[ni][nj][nk] > dist[cur.i][cur.j][cur.k] + 1)
			{
				dist[ni][nj][nk] = dist[cur.i][cur.j][cur.k] + 1;
				Q.push({ ni,nj,nk });
			}
		}
	}
	int ans = 2e9;
	for (int i = 0; i <= K; i++) ans = min(ans, dist[H][W][i]);
	printf("%d", ans == 2e9 ? -1 : ans);
	return 0;
}