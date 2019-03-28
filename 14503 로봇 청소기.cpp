#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, num = 0;
int grid[51][51];
pair<int, int> dir[4] = { {-1,0},{0,1},{1,0},{0,-1} }; // ºÏ µ¿ ³² ¼­
void f(int curi, int curj, int curdir, bool isback)
{
	if (!isback) {
		grid[curi][curj] = 2; num++;
	}
	int nextdir = curdir, loop = 0;
	while (loop < 4)
	{
		nextdir = (nextdir + 3) % 4; loop++;
		int nexti = curi + dir[nextdir].first, nextj = curj + dir[nextdir].second;
		if (!grid[nexti][nextj]) {
			f(nexti, nextj, nextdir, false);
			return;
		}
	}
	nextdir = (curdir + 2) % 4;
	if (grid[curi + dir[nextdir].first][curj + dir[nextdir].second] == 1) {
		return;
	}
	f(curi + dir[nextdir].first, curj + dir[nextdir].second, curdir, true);
	return;
}

int main()
{
	int R, C, D;
	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &R, &C, &D);

	for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++) scanf("%d",&grid[i][j]);
	f(R + 1, C + 1, D, false);
	printf("%d", num);
	return 0;
}