#include <cstdio>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

const int MN = 50 + 5;
const int INF = 1234567890;

struct pos
{
	int i;
	int j; // 중심 좌표
	int dir; // dir-0 : 수평, dir-1 : 수직

	pos() {}
	pos(int i, int j, int dir) : i(i), j(j), dir(dir) {}
};


int N;
char map[MN][MN];
int dist[MN][MN][2];
const int di[] = { -1, 0, 1, 0 }, dj[] = { 0, -1, 0, 1 }; // 상 좌 하 우
pos S, E;
queue<pos> Q;

bool safe(int i, int j, int dir)
{
	if (dir == 0)
		return i >= 1 && i <= N && j - 1 >= 1 && j + 1 <= N
		&& map[i][j - 1] != '1' && map[i][j] != '1' && map[i][j + 1] != '1';
	else return i - 1 >= 1 && i + 1 <= N && j >= 1 && j <= N
		&& map[i - 1][j] != '1' && map[i][j] != '1' && map[i + 1][j] != '1';
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%s", map[i] + 1);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (j <= N - 2 && map[i][j] == 'B' && map[i][j + 1] == 'B' && map[i][j + 2] == 'B')
			{
				S.i = i, S.j = j + 1, S.dir = 0;
			}
			if (i <= N - 2 && map[i][j] == 'B' && map[i + 1][j] == 'B' && map[i + 2][j] == 'B')
			{
				S.i = i + 1, S.j = j, S.dir = 1;
			}
			if (j <= N - 2 && map[i][j] == 'E' && map[i][j + 1] == 'E' && map[i][j + 2] == 'E')
			{
				E.i = i, E.j = j + 1, E.dir = 0;
			}
			if (i <= N - 2 && map[i][j] == 'E' && map[i + 1][j] == 'E' && map[i + 2][j] == 'E')
			{
				E.i = i + 1, E.j = j, E.dir = 1;
			}
		}

	memset(dist, -1, sizeof(dist));
	dist[S.i][S.j][S.dir] = 0;
	Q.push(S);

	while (!Q.empty())
	{
		pos cur = Q.front(); Q.pop();
		int ci = cur.i, cj = cur.j, cd = cur.dir;
		//printf("%d %d %d\n", ci, cj, cd);
		if (ci == E.i && cj == E.j && cd == E.dir) break;
		for (int k = 0; k < 4; k++)
		{
			int ni = ci + di[k], nj = cj + dj[k], nd = cd;
			if (safe(ni, nj, nd) && dist[ni][nj][nd] == -1)
			{
				dist[ni][nj][nd] = dist[ci][cj][cd] + 1;
				Q.push({ ni, nj, nd });
			}
		}
		if (safe(ci, cj, 0) && safe(ci - 1, cj, 0) && safe(ci + 1, cj, 0) &&
			dist[ci][cj][!cd] == -1)
		{
			dist[ci][cj][!cd] = dist[ci][cj][cd] + 1;
			Q.push({ ci, cj, !cd });
		}
	}
	printf("%d", dist[E.i][E.j][E.dir] == -1 ? 0 : dist[E.i][E.j][E.dir]);

	return 0;
}