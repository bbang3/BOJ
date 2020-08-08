#include <bits/stdc++.h>
using namespace std;

const int MN = 1e3 + 5;
const int MM = 2 * 1e2 + 5;
const int INF = 2e9;

int D[MN][MM][15], C[MN];
int N, M;
// D[i][j][k] : i번째 날 / 현재 남은 잔고 j / 오늘 쓸 잔고 k 일 때 최소 박탈감
int f(int i, int j, int k)
{
	int& ret = D[i][j][k];
	if (ret != -1) return ret;
	if (i == 1) return 0;
	ret = INF;
	for (int nextk = 0; nextk <= min(j - k, 10); nextk++)
	{
		int d = (C[i - 1] + nextk) - (C[i] + k);
		if (d < 0) ret = min(ret, f(i - 1, j - k, nextk));
		else ret = min(ret, d * d + f(i - 1, j - k, nextk));
	}
	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%d", C + i);
	memset(D, -1, sizeof D);
	
	int ans = INF;
	for (int k = 0; k <= 10; k++) // 하루 지출은 10을 넘길 필요가 없다.
		ans = min(ans, f(N, M, k));
	printf("%d", ans);
	return 0;
}