#include <bits/stdc++.h>
using namespace std;

struct Pos
{
	int i, j;
	int m;

	bool operator < (const Pos& b) const
	{
		return m > b.m;
	}
};

struct Unit
{
	int m, t, a, b;
};

const int MX = 500 + 5;
const int INF = 1e9;
const int di[] = { -1,1,0,0, }, dj[] = { 0,0,-1,1 };

int N, H, W, M;
int mp[MX][MX], team[MX][MX]; // 험준도, 현재 상태
int dist[MX][MX];

int height[15];
Unit units[MX * MX / 4];

bool safe(int i, int j) { return i >= 0 && i < H&& j >= 0 && j < W&& mp[i][j] != -1; }

bool combat(int i, int j, int curt)
{
	bool occur = false;
	for (int k = 0; k < 4; k++)
	{
		int ni = i + di[k], nj = j + dj[k];
		if (!safe(ni, nj)) continue;
		if (team[ni][nj] == -1) continue;

		if (team[ni][nj] != curt)
		{
			occur = true;
			break;
		}
	}
	return occur;
}

bool dijkstra(Unit u, Pos dest)
{
	if (team[dest.i][dest.j] >= 0 || mp[dest.i][dest.j] == -1) return false;

	//memset(dist, -1, sizeof dist);
	for (int i = u.a - 30; i <= u.a + 30; i++)
		for (int j = u.b - 30; j <= u.b + 30; j++)
			if (i >= 0 && i < H && j >= 0 && j < W)
				dist[i][j] = INF;

	priority_queue<Pos> PQ;
	dist[u.a][u.b] = 0;
	PQ.push({ u.a, u.b, 0 });
	while (!PQ.empty())
	{
		Pos cur = PQ.top();
		PQ.pop();

		if (cur.i == dest.i && cur.j == dest.j) break;
		if (cur.m != dist[cur.i][cur.j]) continue;
		//printf("%d %d\n", cur.i, cur.j);

		for (int k = 0; k < 4; k++)
		{
			int ni = cur.i + di[k], nj = cur.j + dj[k];
			if (!safe(ni, nj)) continue;
			if (!(ni == dest.i && nj == dest.j) && combat(ni, nj, u.t)) continue;
			if (team[ni][nj] != -1 && team[ni][nj] != u.t) continue;

			int nm = dist[cur.i][cur.j] + mp[ni][nj];
			if (nm > u.m) continue;

			if (dist[ni][nj] > nm)
			{
				dist[ni][nj] = nm;
				PQ.push({ ni, nj, nm });
			}
		}
	}
	if (dist[dest.i][dest.j] == INF) return false;
	return true;
}

int main()
{
	scanf("%d %d %d", &N, &H, &W);
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			scanf("%d", &mp[i][j]);

	for (int i = 1; i <= N; i++)
		scanf("%d", &height[i]);

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			mp[i][j] = height[mp[i][j]]; // 번호 말고 험준도 값으로 바꿈
			team[i][j] = -1;
		}

	scanf("%d", &M);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d %d %d", &units[i].m, &units[i].t, &units[i].a, &units[i].b);
		team[units[i].a][units[i].b] = units[i].t;
	}

	int K;
	scanf("%d", &K);
	while (K--)
	{
		int u, a, b;
		scanf("%d %d %d", &u, &a, &b);

		if (dijkstra(units[u], { a, b })) // 이동 성공
		{
			team[units[u].a][units[u].b] = -1;
			team[a][b] = units[u].t;

			units[u].a = a;
			units[u].b = b;
		}
	}
	for (int i = 1; i <= M; i++) printf("%d %d\n", units[i].a, units[i].b);

	return 0;
}