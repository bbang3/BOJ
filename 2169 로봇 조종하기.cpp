#include <bits/stdc++.h>
using namespace std;

const int MN = 1000 + 5;
const int INF = 1e9;

int value[MN][MN];
int D[MN][MN][3]; // 0: 왼쪽, 1: 오른쪽, 2: 아래쪽
bool chk[MN][MN];

int M, N;
const int di[] = { 0, 0 ,1 }, dj[] = { -1, 1, 0 };

// D[i][j][from] : 이전에 dir 방향 사용, (i, j)에서 (N, M)까지 가는 동안 얻을 수 있는 최대 가치
int f(int i, int j, int dir)
{
	int& ret = D[i][j][dir];
	chk[i][j] = true;
	if (ret != -INF) return ret;
	if (i == N && j == M) return ret = value[i][j];

	for (int ndir = 0; ndir < 3; ndir++)
	{
		if ((ndir == 0 && dir == 1) || (ndir == 1 && dir == 0)) continue;

		int ni = i + di[ndir], nj = j + dj[ndir];
		if (1 <= ni && ni <= N && 1 <= nj && nj <= M)
		{
			ret = max(ret, value[i][j] + f(ni, nj, ndir)); // 0 -> 1, 1 -> 0
		}
	}
	//printf("%d %d %d %d\n", i, j, dir, ret);
	chk[i][j] = false;
	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &value[i][j]);
			D[i][j][0] = D[i][j][1] = D[i][j][2] = -INF;
		}

	printf("%d\n", f(1, 1, 2));
	return 0;
}