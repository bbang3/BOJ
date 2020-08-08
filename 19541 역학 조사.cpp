#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 5;
int N, M;
int res[MX], init[MX], tmp[MX];
vector<int> meeting[MX];
// 역추적 후 시뮬레이션 -> 가능하면 YES
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		int k, n;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++)
		{
			scanf("%d", &n);
			meeting[i].push_back(n);
		}
	}
	for (int i = 1; i <= N; i++) scanf("%d", &res[i]);
	for (int i = 1; i <= N; i++) init[i] = res[i];

	for (int i = M; i >= 1; i--)
	{
		bool noninfect = false;
		for (int n : meeting[i])
		{
			if (init[n] == 0)
			{
				noninfect = true;
				break;
			}
		}

		if (noninfect)
		{
			for (int n : meeting[i])
				init[n] = 0;
		}
	}

	for (int n = 1; n <= N; n++) tmp[n] = init[n];
	for (int i = 1; i <= M; i++)
	{
		bool infect = false;
		for (int n : meeting[i])
			if (tmp[n])
			{
				infect = true;
				break;
			}

		if (infect)
		{
			for (int n : meeting[i])
				tmp[n] = 1;
		}
	}

	for (int n = 1; n <= N; n++)
		if (tmp[n] != res[n])
		{
			puts("NO");
			return 0;
		}

	puts("YES");
	for (int n = 1; n <= N; n++) printf("%d ", init[n]);

	return 0;
}