#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

struct edge
{
	int dest;
	int w;
};

const int MN = 100 + 5;
int N, M;
vector<edge> G[MN];
vector<int> basis;
int ind[MN];
int D[MN][MN]; // D[i][j] : i번 부품을 만드는 데 필요한 "기본 부품" j의 개수
queue<int> M;

int main()
{
	scanf("%d %d", &N, &M);

	int x, y, k;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &x, &y, &k);
		G[y].push_back({ x, k });
		ind[x]++;
	}

	for (int i = 1; i <= N; i++)
		if (ind[i] == 0)
		{
			M.push(i);
			basis.push_back(i);
			D[i][i] = 1;
		}

	while (!M.empty())
	{
		int cur = M.front(); M.pop();
		for (edge e : G[cur])
		{
			for (int i = 1; i <= N; i++)
			{
				D[e.dest][i] += D[cur][i] * e.w;
			}

			ind[e.dest]--;
			if (ind[e.dest] == 0)
				M.push(e.dest);
		}
	}

	for (int b : basis)
	{
		printf("%d %d\n", b, D[N][b]);
	}

	return 0;
}