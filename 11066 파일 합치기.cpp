#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <limits.h>
using namespace std;

int K;
int file[500 + 5], psum[500 + 5];
int D[500 + 5][500 + 5]; // D[i][j] : [i, j] 구간 합치는 최소 비용
// D[i][j] = min(D[i][k] + D[k + 1][j] + sum(i, j)) where k = i ~ j - 1

int f(int i, int j)
{
	int &ret = D[i][j];
	if (i == j) return 0;
	if (ret != -1) return ret;

	ret = INT_MAX;
	for (int k = i; k <= j - 1; k++)
		ret = min(ret, f(i, k) + f(k + 1, j) + psum[j] - psum[i - 1]);

	return ret;
}

int main()
{
	int T; scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &K);

		memset(D, -1, sizeof(D));
		for (int i = 1; i <= K; i++) 
			scanf("%d", file + i), psum[i] = psum[i-1] + file[i];

		printf("%d\n", f(1, K));
	}
	return 0;
}