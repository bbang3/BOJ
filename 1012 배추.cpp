#include <cstdio>
#include <memory.h>
int M, N, S;
int arr[51][51];
void f(int i, int j)
{
	if (arr[i][j] == 0) return;
	if (i < 0 || j < 0 || i >= N || j >= M) return;

	arr[i][j] = 0;

	f(i + 1, j);
	f(i - 1, j);
	f(i, j + 1);
	f(i, j - 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(arr, 0, sizeof(arr));
		scanf("%d%d%d", &M, &N, &S);
		while (S--)
		{



			int a, b, cnt = 0;
			scanf("%d%d", &a, &b);
			arr[b][a] = 1;
		}
		int ans = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (arr[i][j] == 1)
				{
					ans++;
					f(i, j);
				}

		printf("%d\n", ans);
	}
	return 0;
}