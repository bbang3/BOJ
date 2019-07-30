#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
int candy[1000 + 5][1000 + 5];
int D[1000 + 5][1000 + 5]; // D[i][j] : (i,j)에서 얻을 수 있는 사탕 개수

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) scanf("%d", &candy[i][j]);

	int di[] = { -1, -1, 0 }, dj[] = { -1, 0, -1 };
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				int nexti = i + di[k], nextj = j + dj[k];
				D[i][j] = max(D[i][j], D[nexti][nextj]);
			}
			D[i][j] += candy[i][j];
		}

	printf("%d", D[N][M]);
	return 0;
}