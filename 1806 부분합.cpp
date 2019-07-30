#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 1e5 + 5;
int N, S;
int arr[MN];
int main()
{
	scanf("%d %d", &N, &S);

	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);

	int sum = 0, s = 1, e = 1, ans = 987654321;
	for (int i = 1; i <= N; i++)
	{
		sum += arr[i];
		if (sum >= S)
		{
			while (sum >= S)
			{
				ans = min(ans, i - s + 1);
				sum -= arr[s];
				s++;
			}
		}
	}
	printf("%d", ans == 987654321 ? 0 : ans);

	return 0;
}