#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;

int N;
int arr[102][102];
bool visit[102][102];
queue<pair<int, int>> M;
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

bool issafe(int i, int j)
{
	return i >= 1 && i <= N && j >= 1 && j <= N;
}

void flood_fill(int curi, int curj)
{
	if (!issafe(curi, curj) || visit[curi][curj]) return;
	visit[curi][curj] = true;
	
	for (int i = 0; i < 4; i++)
		flood_fill(curi + di[i], curj + dj[i]);
}

void flood_fill_byqueue(int curi, int curj)
{
	M.push({ curi,curj });
	while (!M.empty())
	{
		int curi = M.front().first, curj = M.front().second;
		M.pop();
		visit[curi][curj] = true;

		for (int i = 0; i < 4; i++)
		{
			int nexti = curi + di[i], nextj = curj + dj[i];
			if (issafe(nexti, nextj) && !visit[nexti][nextj])
			{
				M.push({ nexti,nextj });
				visit[nexti][nextj] = true;
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	int maxh = -1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &arr[i][j]);
			maxh = max(maxh, arr[i][j]);
		}
	int ans = -1;
	for (int h = 0; h <= maxh; h++)
	{
		int cnt = 0;

		memset(visit, 0, sizeof(visit));
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (arr[i][j] <= h) visit[i][j] = true;

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (!visit[i][j])
					flood_fill_byqueue(i, j), cnt++;
					//flood_fill(i, j), cnt++;

		ans = max(ans, cnt);
	}
	printf("%d", ans);
	return 0;
}