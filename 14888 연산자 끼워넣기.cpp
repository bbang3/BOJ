#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int arr[15], opnum[4];
int N;
int minres = 2e9, maxres = -2e9;

void f(int result, int idx) // idx번째 숫자 계산할 차례, 이전 계산결과가 result
{
	//printf("%d %d\n", result, idx);
	if (idx == N + 1)
	{
		minres = min(result, minres);
		maxres = max(result, maxres);
	}

	for (int i = 0; i < 4; i++)
	{
		if (opnum[i] <= 0) continue;

		opnum[i]--;
		int cur = arr[idx];
		if (i == 0) f(result + cur, idx + 1);
		else if (i == 1) f(result - cur, idx + 1);
		else if (i == 2) f(result * cur, idx + 1);
		else f(result / cur, idx + 1);
		opnum[i]++;
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", arr + i);
	scanf("%d %d %d %d", &opnum[0], &opnum[1], &opnum[2], &opnum[3]);

	f(arr[1], 2);
	printf("%d\n%d", maxres, minres);

	return 0;
}