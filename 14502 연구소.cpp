#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
int N, M;
int ans = 0;
int map[10][10];
vector<pii> virusPos;
const int di[] = { -1,0,1,0 }, dj[] = { 0,-1,0,1 };
int getSafeSize();
void dfs(int i, int j, int map[10][10]);

bool safe(int i, int j)
{
	return i >= 1 && i <= N && j >= 1 && j <= M;
}

void bruteForce(int pi, int pj, int wallcnt) // 3개의 벽을 임의로 설정 후 바이러스 퍼뜨림
{
	if (wallcnt == 3)
	{
		ans = max(ans, getSafeSize());
		return;
	}

	int i, j = pj;
	for (i = pi; i <= N; i++)
		for (j = (i == pi) ? pj : 1; j <= M; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				bruteForce(i, j, wallcnt + 1);
				map[i][j] = 0;
			}
		}
}

int getSafeSize() // 안전 영역 크기 구하기
{
	int tmp[10][10];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			tmp[i][j] = map[i][j];

	for (pii v : virusPos)
		dfs(v.first, v.second, tmp);

	int cnt = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (tmp[i][j] == 0) cnt++;

	return cnt;
}

void dfs(int i, int j, int map[10][10])
{
	map[i][j] = 2;

	for (int k = 0; k < 4; k++)
	{
		int ni = i + di[k], nj = j + dj[k];
		if (safe(ni, nj) && map[ni][nj] == 0)
			dfs(ni, nj, map);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2)
				virusPos.push_back({ i ,j });
		}

	bruteForce(1, 1, 0);
	printf("%d", ans);
	return 0;
}