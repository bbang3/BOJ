#include <bits/stdc++.h>
using namespace std;

const int MN = 100 + 5;
const int INF = -1e9;
const int INIT = -2e9;
int N, M;
int arr[MN], psum[MN];
int D[MN][MN]; // D[i][j]: [i, N]에서 j개의 구간을 고를 때 최대 합
// D[i][j] = D[i + 1][j] (i번째 요소 선택 X)
// 또는 max(D[k + 2][j - 1] + sum(i, k)) for i <= k <= N (i번째 요소 선택)

int f(int i, int j)
{
	if (j == 0) return 0;
	if (i > N) return INF;
	int& ret = D[i][j];
	if (ret != INIT) return ret;

	ret = max(ret, f(i + 1, j));
	for (int k = i; k <= N; k++)
		ret = max(ret, f(k + 2, j - 1) + psum[k] - psum[i - 1]);
	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", arr + i), psum[i] = psum[i - 1] + arr[i];
	fill(&D[0][0], &D[MN - 1][MN - 1], INIT);

	printf("%d", f(1, M));
	return 0;
}