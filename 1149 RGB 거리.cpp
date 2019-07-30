#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int D[3][1000 + 5];
// D[i][0] : i번째 줄의 스티커를 떼지 않음, [1] : i번째 줄의 위쪽 스티커 남김, [2] : i번째 줄의 아래쪽 스티커 남김
int wine[3][1000 + 5];
int N;

int f(int color, int i) // i번째 집을 color로 칠했을 때 최소 비용 (0 - R, 1 - G, 2 - B)
{
	if (i == 0) return 0;
	if (D[color][i] != -1) return D[color][i];

	if (color == 0)
	{
		D[color][i] = min(f(1, i - 1), f(2, i - 1)) + wine[color][i];
	}
	else if (color == 1)
	{
		D[color][i] = min(f(0, i - 1), f(2, i - 1)) + wine[color][i];
	}
	else D[color][i] = min(f(0, i - 1), f(1, i - 1)) + wine[color][i];

	return D[color][i];
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) scanf("%d %d %d", &wine[0][i], &wine[1][i], &wine[2][i]);
	memset(D, -1, sizeof(D));

	printf("%d", min(f(0, N), min(f(1, N), f(2, N))));

	return 0;
}