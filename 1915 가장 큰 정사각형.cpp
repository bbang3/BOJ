#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 5;
int N, M;
int arr[MAX][MAX];
int D[MAX][MAX];

int getS(int si, int sj, int ei, int ej)
{
	return D[ei][ej] - D[ei][sj - 1] - D[si - 1][ej] + D[si - 1][sj - 1];
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", &arr[i][j]);
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1] + arr[i][j];
	D[1][1];
	
	for (int len = min(N, M); len >= 1; len--)
	{
		for (int i = 1; i <= N - len + 1; i++)
		{
			for (int j = 1; j <= M - len + 1; j++)
			{
				if (getS(i, j, i + len - 1, j + len - 1) == len * len)
				{
					printf("%d", len * len);
					return 0;
				}
			}
		}
	}

	puts("0");

	return 0;
}