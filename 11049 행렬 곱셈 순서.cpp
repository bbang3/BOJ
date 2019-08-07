#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

struct mat { int r; int c; };
const int MN = 500 + 5;
mat M[MN];
int D[MN][MN]; // D[i][j] : i번째 ~ j번째 행렬에 대한 최소 곱셈 횟수
int N;
// D[i][j] = min(D[i][k] + D[k + 1][j] + i번째 행 * k번째 열 * j번째 열) (i <= k < j)
int f(int i, int j)
{
	int &ret = D[i][j];
	if (ret != -1) return ret;
	if (i == j) return 0;

	ret = 1LL << 31 - 1;
	for (int k = i; k < j; k++) 
		ret = min(ret, M[i].r * M[k].c * M[j].c + f(i, k) + f(k + 1, j));

	return ret;
}


int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d %d", &M[i].r, &M[i].c);

	memset(D, -1, sizeof(D));
	printf("%d", f(1, N));

	return 0;
}