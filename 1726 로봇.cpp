#include <bits/stdc++.h>
using namespace std;


struct Pos
{
	int i;
	int j;
	int dir;
};

// 0: 동, 1: 서, 2: 남, 3: 북
const int di[] = { 0,0,1,-1 }, dj[] = { 1,-1,0,0 };
int N, M;
int mp[105][105];
bool visited[105][105][4];
Pos S, E;

int turn(int curdir, int flag)
{
	const int nxtdir[] = { 2, 3, 1, 0 };
	const int prvdir[] = { 3, 2, 0, 1 };

	if (flag == -1) // cw
		return nxtdir[curdir];
	else
		return prvdir[curdir];
}

bool safe(int i, int j)
{
	return 1 <= i && i <= N && 1 <= j && j <= M;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &mp[i][j]);

	scanf("%d %d %d", &S.i, &S.j, &S.dir);
	scanf("%d %d %d", &E.i, &E.j, &E.dir);
	S.dir--, E.dir--;

	queue<Pos> Q;
	visited[S.i][S.j][S.dir] = true;
	Q.push(S);
	int ans = 0;

	while (!Q.empty())
	{
		bool isFind = false;
		int qsz = Q.size();
		for (int loop = 0; loop < qsz; loop++)
		{
			Pos cur = Q.front();
			Q.pop();

			if (cur.i == E.i && cur.j == E.j && cur.dir == E.dir)
			{
				isFind = true;
				break;
			}

			for (int move = 1; move <= 3; move++)
			{
				int ni = cur.i + di[cur.dir] * move, nj = cur.j + dj[cur.dir] * move;
				if (!safe(ni,nj) || mp[ni][nj] == 1) break; // 앞이 막혀있으면 몇 칸이든 이동 불가

				if (!visited[ni][nj][cur.dir])
				{
					Q.push({ ni, nj, cur.dir });
					visited[ni][nj][cur.dir] = true;
				}
			}

			int ndir = turn(cur.dir, -1);
			if (!visited[cur.i][cur.j][ndir])
			{
				Q.push({ cur.i, cur.j, ndir });
				visited[cur.i][cur.j][ndir] = true;
			}

			ndir = turn(cur.dir, 1);
			if (!visited[cur.i][cur.j][ndir])
			{
				Q.push({ cur.i, cur.j, ndir });
				visited[cur.i][cur.j][ndir] = true;
			}
		}
		if (isFind) break;
		ans++;
	}
	printf("%d", ans);

	return 0;
}