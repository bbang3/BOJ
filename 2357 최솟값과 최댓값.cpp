#include <cstdio>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;

const int MN = 1e6 + 5;
const int MOD = 1e9 + 7;
typedef long long ll;

int arr[MN];
ll minseg[4 * MN], maxseg[4 * MN];

void init(int node, int start, int end)
{
	if (start == end)
	{
		minseg[node] = maxseg[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);

	minseg[node] = min(minseg[node * 2], minseg[node * 2 + 1]);
	maxseg[node] = max(maxseg[node * 2], maxseg[node * 2 + 1]);
	return;
}

ll getmax(int node, int start, int end, int left, int right)
{
	if (right < start || left > end) return -1;
	if (left <= start && end <= right) return maxseg[node];

	int mid = (start + end) / 2;
	return max(getmax(node * 2, start, mid, left, right), getmax(node * 2 + 1, mid + 1, end, left, right));
}

ll getmin(int node, int start, int end, int left, int right)
{
	if (right < start || left > end) return 1 << 30;
	if (left <= start && end <= right) return minseg[node];

	int mid = (start + end) / 2;
	return min(getmin(node * 2, start, mid, left, right), getmin(node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%d", arr + i);

	init(1, 1, N);
	int a, b;
	while (M--)
	{
		scanf("%d %d", &a, &b);
		printf("%lld %lld\n", getmin(1, 1, N, a, b), getmax(1, 1, N, a, b));
	}

	return 0;
}