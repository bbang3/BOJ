#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

struct Pos
{
	int i, j;
};

const int MN = 500 + 5;
int map[MN][MN];
int N;
const int di[] = { -1,0,1,0 }, dj[] = { 0,-1,0,1 };
int D[MN][MN]; // D[i][j]: (i, j)에서 시작하는 증가 경로 길이
			   // D[i][j] = max(D[m][n] + 1) where (m, n)은 map[m][n] > map[i][j]이고 (i, j)와 인접
			   // base case: 움직일 곳이 없음 -> D[i][j] = 1

bool safe(int i, int j) { return i >= 1 && i <= N && j >= 1 && j <= N; }

int f(int i, int j)
{
	int& ret = D[i][j];
	if (ret != -1) return ret;

	ret = 1;
	for (int k = 0; k < 4; k++)
	{
		int ni = i + di[k], nj = j + dj[k];
		if (safe(ni, nj) && map[ni][nj] > map[i][j])
			ret = max(ret, f(ni, nj) + 1);
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]), D[i][j] = -1;

	int ans = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			ans = max(ans, f(i, j));

	printf("%d", ans);
	return 0;
}