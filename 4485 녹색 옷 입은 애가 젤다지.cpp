#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

const int MN = 125 + 5;

struct edge
{
	int i;
	int j;
	int w;

	edge(int i, int j, int w) : i(i), j(j), w(w) {}

	bool operator < (const edge a) const
	{
		return w > a.w;
	}
};

int N;
priority_queue<edge> PQ;
int map[MN][MN];
int cost[MN][MN];

bool safe(int i, int j) { return i >= 1 && i <= N && j >= 1 && j <= N; }

int main()
{
	int loop = 1;
	while (1)
	{
		scanf("%d", &N);
		if (N == 0) return 0;

		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= N; j++)
			{
				cost[i][j] = INF;
				scanf("%d", &map[i][j]);
			}

		cost[1][1] = map[1][1];
		PQ.push(edge(1, 1, cost[1][1]));

		int di[] = { -1,0,1,0 }, dj[] = { 0,-1,0,1 };
		while (!PQ.empty())
		{
			edge cur = PQ.top(); PQ.pop();

			if (cur.w != cost[cur.i][cur.j]) continue;
			if (cur.i == N && cur.j == N) break;

			for (int k = 0; k < 4; k++)
			{
				int ni = cur.i + di[k], nj = cur.j + dj[k];

				if (safe(ni, nj) && cost[cur.i][cur.j] + map[ni][nj] < cost[ni][nj])
				{
					cost[ni][nj] = cost[cur.i][cur.j] + map[ni][nj];
					PQ.push(edge(ni, nj, cost[ni][nj]));
				}
			}
		}

		printf("Problem %d: %d\n", loop++, cost[N][N]);
	}

	return 0;
}