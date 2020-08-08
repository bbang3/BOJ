#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 5;
int N, M;
int arr[MAX][MAX];
int D[MAX][MAX]; // D[i][j]: (i, j)를 오른쪽 아래 꼭짓점으로 하는 정사각형의 개수
// D[i][j] = min(D[i - 1][j, D[i][j - 1], D[i - 1][j - 1]) + 1 (arr[i][j] = 0인 경우 D[i][j] = 0)

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", &arr[i][j]);

	int mxlen = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j] == 0) continue;
			D[i][j] = min({ D[i - 1][j], D[i][j - 1], D[i - 1][j - 1] }) + 1;
			mxlen = max(mxlen, D[i][j]);
		}
	printf("%d", mxlen * mxlen);
	return 0;
}