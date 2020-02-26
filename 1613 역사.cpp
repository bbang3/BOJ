#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 500 + 5;
int D[MN][MN]; // D[i][j]: i에서 j로 도달 가능한지 여부

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		int src, dest;
		scanf("%d %d", &src, &dest);
		D[src][dest] = 1;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				D[i][j] |= D[i][k] && D[k][j];
	// floyd-warshall
	int Q;
	scanf("%d", &Q);
	while (Q--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (D[a][b]) puts("-1");
		else if (D[b][a]) puts("1");
		else puts("0");
	}
	return 0;
}