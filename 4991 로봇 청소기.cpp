#include <cstdio>
#include <algorithm>
#include <queue>
#include <string.h>
#include <map>
using namespace std;

struct pos
{
	int i;
	int j;
};

char grid[30][30];
int dist[30][30], mat[30][30];
const int di[] = { -1,0,1,0 }, dj[] = { 0,-1,0,1 };
int W, H, idx = 1;
pos P[15];
map<pos, int> M;

bool safe(int i, int j) { return i >= 1 && i <= H && j >= 1 && j <= W && grid[i][j] != 'x'; }

void bfs(int n)
{
	queue<pos> Q;
	Q.push({ P[n].i, P[n].j });
	memset(dist, -1, sizeof(dist));
	dist[P[n].i][P[n].j] = 0;

	while (!Q.empty())
	{
		int ci = Q.front().i, cj = Q.front().j;
		Q.pop();
		if (!(ci == P[n].i && cj == P[n].j) && grid[ci][cj] == '*' || grid[ci][cj] == 'o')
		{
			for (int m = 0; m < idx; m++)
			{
				if (P[m].i == ci && P[m].j == cj)
					mat[n][m] = mat[m][n] = dist[ci][cj];
			}
		}
		for (int k = 0; k < 4; k++)
		{
			int ni = ci + di[k], nj = cj + dj[k];
			if (safe(ni, nj) && dist[ni][nj] == -1)
			{
				dist[ni][nj] = dist[ci][cj] + 1;
				Q.push({ ni, nj });
			}
		}
	}
	return;
}

int main()
{
	while (1)
	{
		scanf("%d %d", &W, &H);
		if (W == 0 && H == 0) return 0;
		idx = 1;
		memset(mat, 0, sizeof(mat));
		for (int i = 1; i <= H; i++) scanf("%s", grid[i] + 1);

		for (int i = 1; i <= H; i++)
			for (int j = 1; j <= W; j++)
				if (grid[i][j] == 'o') P[0] = { i, j };
				else if (grid[i][j] == '*')
					P[idx++] = { i, j };

		for (int i = 0; i < idx; i++) bfs(i);

		bool can = true;
		for (int i = 1; i < idx; i++)
			if (mat[0][i] == 0)
			{
				can = false;
				break;
			}
		if (!can)
		{
			puts("-1");
			continue;
		}
		vector<int> V;
		for (int i = 1; i < idx; i++) V.push_back(i);

		int mdist = 1234567890;
		do
		{
			int sum = mat[0][V[0]];
			for (int i = 1; i < V.size(); i++)
				sum += mat[V[i - 1]][V[i]];
			//printf("%d ", sum);
			mdist = min(sum, mdist);
		} while (next_permutation(V.begin(), V.end()));
		printf("%d\n", mdist == 1234567890 ? -1 : mdist);
	}

	return 0;
}