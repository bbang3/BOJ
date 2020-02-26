#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 1e3 + 5;
const int MM = 2 * 1e2 + 5;

int D[MN][MM][MM], C[MM];
int N, M;
// D[i][j][k] : i번째 날 / 잔고 j만큼 사용 / 오늘 지출 k
int f(int i, int j, int k)
{
	int &ret = D[i][j][k];
	if (ret != -1) return ret;
	if (i == N + 1) return 0;
	ret = 2e9;
	if (C[i] <= C[i + 1]) ret = f(i + 1, j, C[i]);
	for (int use = 0; use <= C[i] - C[i + 1]; use++)
	{
		if (use > j || j + use > M) continue;
		int d = C[i] + use - C[i - 1];
		ret = min(ret, f(i - 1, j - use, C[i] + use) + d * d);
	}
	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) scanf("%d", C + i);
	printf("%d", f(N, 0, C[N]));
	return 0;
}