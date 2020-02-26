#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 1000 + 5;
int value[MN][MN], D[MN][MN];
bool chk[MN][MN];
int M, N;
const int di[] = { -1, 0 ,0 }, dj[] = { 0, -1, 1 };

int f(int i, int j) // D[i][j] : (i, j)에서 (N, M)까지 가는 동안 얻을 수 있는 최대 가치
{
	if (D[i][j] != -1e9) return D[i][j];
	if (i == 1 && j == 1) return D[i][j] = value[i][j];
	int& ret = D[i][j];

	for (int k = 0; k < 3; k++)
	{
		int ni = i + di[k], nj = j + dj[k];
		if (ni >= 1 && ni <= N && nj >= 1 && nj <= M && !chk[ni][nj])
		{
			chk[ni][nj] = true;
			ret = max(ret, value[i][j] + f(ni, nj));
			chk[ni][nj] = false;
		}
	}
	
	printf("%d %d %d\n", i, j, ret);
	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &value[i][j]);

	fill(&D[0][0], &D[0][0] + MN * MN, -1e9);
	printf("%d\n", f(N, M));
	for (int i = 1; i <= N; i++, puts(""))
		for (int j = 1; j <= M; j++)
			printf("%d ", D[i][j]);
	return 0;
}