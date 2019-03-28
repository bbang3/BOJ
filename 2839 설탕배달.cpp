#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int ans = 0x7fffffff;
	for (int i = 0; 5 * i <= N; i++)
	{
		for (int j = 0; 5 * i + 3 * j <= N; j++)
		{
			if (5 * i + 3 * j == N)
				ans = min(ans, i + j);
		}
	}
	printf("%d", ans == 0x7fffffff ? -1 : ans);
	return 0;
}