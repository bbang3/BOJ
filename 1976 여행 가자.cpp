#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 200 + 5;
const int MM = 1000 + 5;

int N, M;
int G[MN][MN];
int p[MN], plan[MM];

int find(int n)
{
	if (p[n] == n) return n;
	return p[n] = find(p[n]);
}

void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return;
	if (a < b)
		p[a] = b;
	else p[b] = a;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) p[i] = i;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &G[i][j]);
			if (G[i][j])
			{
				merge(i, j);
			}
		}

	for (int i = 1; i <= N; i++) printf("%d ", p[i]); puts("");
	for (int i = 1; i <= M; i++)
		scanf("%d", &plan[i]);


	for (int i = 2; i <= M; i++)
	{
		printf("%d %d", find(plan[i - 1]), find(plan[i - 1]));
		if (find(plan[i]) != find(plan[i - 1]))
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");

	return 0;
}