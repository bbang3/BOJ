#include <cstdio>
#include <algorithm>
using namespace std;

struct Pos
{
	int i;
	int j;

};
const int MN = 50 + 5;
int R, C, T;
int grid[MN][MN];
Pos s1, s2;
const int d[2][4][2] = {
	{ { -1, 0 },{ 0, 1 },{ 1, 0 },{ 0, -1 } }, // 위쪽
	{ { 1, 0 },{ 0, 1 },{ -1, 0 },{ 0, -1 } } // 아래쪽
};

bool chk(int i, int j)
{
	return i >= 1 && i <= R && j >= 1 && j <= C && grid[i][j] != -1;
}

void spread()
{
	int tmp[MN][MN] = { 0 };
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{
			if (grid[i][j] > 0)
			{
				int curd = grid[i][j];
				for (int k = 0; k < 4; k++)
				{
					int ni = i + d[0][k][0], nj = j + d[0][k][1];
					if (chk(ni, nj))
					{
						tmp[ni][nj] += curd / 5;
						tmp[i][j] -= curd / 5;
					}
				}
			}
		}

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			grid[i][j] += tmp[i][j];
}

void circulate(int si, int sj, bool isClockWise)
{
	int ci = si, cj = sj, dir = 0;

	while (dir < 4)
	{
		int ni = ci + d[isClockWise][dir][0], nj = cj + d[isClockWise][dir][1];
		if (!chk(ni, nj) || (!isClockWise && ni > si) || (isClockWise && ni < si))
		{
			dir++;
			continue;
		}
		if (ci == si && cj == sj) grid[ni][nj] = 0;
		else grid[ci][cj] = grid[ni][nj];

		ci = ni, cj = nj;
	}
	grid[ci][cj] = 0;
}

int main()
{
	scanf("%d %d %d", &R, &C, &T);
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{
			scanf("%d", &grid[i][j]);
			if (grid[i][j] == -1)
			{
				if (s1.i == 0) s1 = { i, j };
				else s2 = { i, j };
			}
		}
	while (T--)
	{
		spread();
		circulate(s1.i, s1.j, false);
		circulate(s2.i, s2.j, true);
	}

	int ans = 0;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (grid[i][j] > 0) ans += grid[i][j];
	printf("%d", ans);
	return 0;
}