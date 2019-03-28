#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
long long ans = 0;
long long partsum[105][105];
int map[105][105];

long long g(int, int, int, int);

void init()
{
	for(int i=1;i<=N;i++)
		for (int j = 1; j <= M; j++)
		{
			partsum[i][j] = partsum[i - 1][j] + partsum[i][j - 1] - partsum[i - 1][j - 1] + map[i][j];
		}
}

long long getsum(int si, int sj, int ei, int ej)
{
	long long sum = 0;

	sum = partsum[ei][ej] - partsum[si - 1][ej] - partsum[ei][sj - 1] + partsum[si - 1][sj - 1];

	return sum;
}

void f() // 큰 직사각형 1개 결정
{
	long long s1 = 0, s2 = 0;
	for (int i = 1; i <= N - 1; i++)
	{
		s1 = getsum(1, 1, i, M);
		s2 = g(i + 1, 1, N, M);
		ans = max(ans, s1 * s2);

		s1 = getsum(N - i + 1, 1, N, M);
		s2 = g(1, 1, N - i, M);
		ans = max(ans, s1 * s2);
	}
	for (int j = 1; j <= M - 1; j++)
	{
		s1 = getsum(1, 1, N, j);
		s2 = g(1, j + 1, N, M);
		ans = max(ans, s1 * s2);

		s1 = getsum(1, M - j + 1, N, M);
		s2 = g(1, 1, N, M - j);
		ans = max(ans, s1 * s2);
	}
}

long long g(int si, int sj, int ei, int ej) // 작은 직사각형 2개 결정
{
	long long s2 = 0, s3 = 0, ret = -1;
	for (int i = si; i <= ei - 1; i++)
	{
		s2 = getsum(si, sj, i, ej);
		s3 = getsum(i + 1, sj, ei, ej);
		ret = max(ret, s2 * s3);
	}
	for (int j = sj; j <= ej - 1; j++)
	{
		s2 = getsum(si, sj, ei, j);
		s3 = getsum(si, j + 1, ei, ej);
		ret = max(ret, s2 * s3);
	}

	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", &map[i][j]);

	init();
	f();
	printf("%lld", ans);
	return 0;
}