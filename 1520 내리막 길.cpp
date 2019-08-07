#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MN = 500 + 5;
int map[MN][MN];
int D[MN][MN]; // D[i][j] : (i, j) ~ (H, W) 경로 개수
int H, W;

bool safe(int i, int j)
{
	return i >= 1 && i <= H && j >= 1 && j <= W;
}

int f(int i, int j)
{
	int& ret = D[i][j];
	if (i == H && j == W) return 1;
	if (ret != -1) return ret;

	ret = 0;
	int di[] = { -1, 1, 0, 0 }, dj[] = { 0,0,-1, 1 }; // 상 하 좌 우
	for (int k = 0; k < 4; k++)
	{
		int ni = i + di[k], nj = j + dj[k];
		if (safe(ni, nj) && map[ni][nj] < map[i][j])
			D[i][j] += f(i + di[k], j + dj[k]);
	}

	return ret;
}

int main()
{
	scanf("%d %d", &H, &W);
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			scanf("%d", &map[i][j]);

	memset(D, -1, sizeof(D));
	printf("%d", f(1, 1));

	return 0;
}