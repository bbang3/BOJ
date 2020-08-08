#include <bits/stdc++.h>
using namespace std;

const int MX = 1000 + 5;

struct Pos
{
	int i;
	int j;
};

int R, C;
int dist[MX][MX]; // dist[i][j]: 불이 (i, j)까지 확산되는 데 걸리는 시간
char mp[MX][MX];
Pos start;
vector<Pos> fire;
const int di[] = { -1, 1, 0, 0 }, dj[] = { 0,0,-1,1 };

bool safe(int i, int j)
{
	return 1 <= i <= R && 1 <= j <= C;
}

void getDist()
{
	queue<Pos> Q;
	fill(&dist[0][0], &dist[MX - 1][MX - 1], 1e9);
	for (Pos f : fire)
	{
		Q.push({ f.i, f.j });
		dist[f.i][f.j] = 0;
	}
	while (!Q.empty())
	{
		Pos cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int ni = cur.i + di[dir], nj = cur.j + dj[dir];
			if (safe(ni, nj) && dist[ni][nj] == 1e9 &&
				(mp[ni][nj] == '.' || mp[ni][nj] == 'J'))
			{
				dist[ni][nj] = dist[cur.i][cur.j] + 1;
				Q.push({ ni, nj });
			}
		}
	}
}

int main()
{
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++)
	{
		scanf("%s", mp[i] + 1);
		for (int j = 1; j <= C; j++)
		{
			if (mp[i][j] == 'J') start = { i, j };
			else if (mp[i][j] == 'F') fire.push_back({ i, j });
		}
	}

	getDist();
	
	bool canEscape = false;
	bool visit[MX][MX] = { false };
	queue<Pos> Q;

	Q.push({ start.i, start.j });
	visit[start.i][start.j] = true;
	int curtime = 0;
	//for (int i = 1; i <= R; i++, puts(""))
	//	for (int j = 1; j <= C; j++)
	//		printf("%d ", dist[i][j]);
	while (!Q.empty())
	{
		int qsz = Q.size();
		for (int i = 0; i < qsz; i++)
		{
			Pos cur = Q.front();
			Q.pop();
			//printf("(%d, %d)\n", cur.i, cur.j);
			if (cur.i == 1 || cur.i == R || cur.j == 1 || cur.j == C)
			{
				canEscape = true;
				break;
			}

			for (int dir = 0; dir < 4; dir++)
			{
				int ni = cur.i + di[dir], nj = cur.j + dj[dir];
				if (safe(ni, nj) && !visit[ni][nj] && mp[ni][nj] == '.' && curtime + 1 < dist[ni][nj])
				{
					visit[ni][nj] = true;
					Q.push({ ni, nj });
				}
			}
		}
		if (canEscape) break;
		curtime++;
	}
	if (canEscape) printf("%d", curtime + 1);
	else puts("IMPOSSIBLE");

	return 0;
}