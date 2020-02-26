#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	int sum = 0, n;
	for (int i = 1; i <= N; i++) scanf("%d", &n), sum += n + 1;

	int cur = M - sum, ans = 0, i;
	for (i = 1; i <= cur / (N + 1); i++)
		ans += (N + 1) * i * i;

	ans += (cur % (N + 1)) * i * i;
	printf("%d", max(0, ans));

	return 0;
}