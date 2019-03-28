#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

int T;
int arr[100 + 5];
int ans[100 + 5];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(ans, 0, sizeof(ans));
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", arr + i);

			ans[i] = arr[i] + 1;
			for (int j = 1; j <= i - 1; j++)
			{
				if (ans[j] >= ans[i]) ans[j]++;
			}
		}
		bool can = false;
		for (int i = 1; i <= N; i++)
		{
			if (ans[i] > N)
			{
				puts("IMPOSSIBLE");
				can = true;
				break;
			}
		}
		if (!can)
		{
			for (int i = 1; i <= N; i++)
				printf("%d ", ans[i]);
			puts("");
		}
	}
	return 0;
}