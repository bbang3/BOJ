#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 987654321
const int MN = 50 + 5;

struct node
{
	int i, j;
	int key; // bitmask

	node() {}
	node(int i, int j, int key) : i(i), j(j), key(key) {}
};

int N, M;
int si, sj;
char map[MN][MN];
int cost[MN][MN][(1 << 6) + 5];
queue<node> M;

bool safe(int i, int j) { return i >= 1 && i <= N && j >= 1 && j <= M; }
bool haskey(char door, int key) { return key & (1 << (door - 'A')); }
int updatekey(char door, int key) { return key |= (1 << (door - 'A')); }

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		getchar();
		for (int j = 1; j <= M; j++)
		{
			scanf("%1c", &map[i][j]);
			if (map[i][j] == '0')
			{
				si = i, sj = j;
			}

			for (int k = 0; k <= (1 << 6); k++)
				cost[i][j][k] = INF;
		}
	}
	//printf("%d %d", si, sj);
	cost[si][sj][0] = 0;
	M.push(node(si, sj, 0));

	int di[] = { -1,0,1,0 }, dj[] = { 0,-1,0,1 }; // ╩С аб го ©Л
	int ans = INF;
	while (!M.empty())
	{
		node cur = M.front(); M.pop();

		if (map[cur.i][cur.j] == '1')
		{
			ans = min(ans, cost[cur.i][cur.j][cur.key]);
			continue;
		}
		for (int k = 0; k < 4; k++)
		{
			int ni = cur.i + di[k], nj = cur.j + dj[k], nk = cur.key;
		
			if (!safe(ni, nj) || map[ni][nj] == '#')
				continue;

			if (map[ni][nj] >= 'A' && map[ni][nj] <= 'F')
			{
				if (!haskey(map[ni][nj], cur.key)) continue;
			}
			else if (map[ni][nj] >= 'a' && map[ni][nj] <= 'f')
			{
				nk = updatekey(map[ni][nj], cur.key);
			}

			if (cost[ni][nj][nk] > cost[cur.i][cur.j][cur.key] + 1)
			{
				cost[ni][nj][nk] = cost[cur.i][cur.j][cur.key] + 1;
				M.push(node(ni, nj, nk));	
			}
		}
	}
	printf("%d", ans == INF ? -1 : ans);
	return 0;
}