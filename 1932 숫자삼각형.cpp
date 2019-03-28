#include <cstdio>
#include <algorithm>
using namespace std;
int tri[501][501];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &tri[i][j]);

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			tri[i][j] += max(tri[i - 1][j], tri[i - 1][j - 1]);
		}
	}
	int ans = -1;
	for (int i = 1; i <= N; i++) ans = max(ans, tri[N][i]);
	printf("%d", ans);
	return 0;
}