#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

const int MN = 5e5 + 5;

struct element
{
	int idx;
	int num;
};

bool cmp(element a, element b)
{
	if (a.num == b.num) return a.idx < b.idx;
	return a.num < b.num;
}

int N;
element arr[MN];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i].num), arr[i].idx = i;

	sort(arr + 1, arr + N + 1, cmp);

	int maxdist = 0;
	for (int i = 1; i <= N; i++)
		maxdist = max(maxdist, arr[i].idx - i);

	printf("%d", maxdist + 1);

	return 0;
}