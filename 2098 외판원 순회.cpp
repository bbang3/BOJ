#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
#define INF 1234567890
const int MN = 20;
const int MN = 1 << 20;
int D[MN][MN]; // D[i][j] : ���� i�� ���ÿ� �ְ�, ���� �湮 ���°� j�� �� �湮���� ���� ���õ��� �湮�ؼ� ���������� ���ư��� �ּ� ���
int G[MN][MN];
int N;
// 0-base
int f(int cur, int visited)
{
	if (D[cur][visited] != -1) return D[cur][visited];
	if (visited == (1 << N) - 1)
	{
		return G[cur][0] != 0 ? G[cur][0] : INF;
	}

	for (int next = 0; next < N; next++)
	{
		if (G[cur][next] != 0 && !(visited & (1 << next)))
		{
			if (D[cur][visited] == -1)
				D[cur][visited] = G[cur][next] + f(next, visited | (1 << next));
			else
				D[cur][visited] = min(D[cur][visited], G[cur][next] + f(next, visited | (1 << next)));
			//if (cur == 0) printf("%d ", D[cur][visited]);
		}
	}
	return D[cur][visited];
}

int main()
{
	scanf("%d", &N);
	memset(D, -1, sizeof(D));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &G[i][j]);

	printf("%d", f(0, 1));
	return 0;
}