#include <cstdio>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;

const int MN = 1e6 + 5;
const int MOD = 1e9 + 7;
typedef long long ll;

int arr[MN];
ll seg[4 * MN];

ll init(int node, int start, int end)
{
	if (start == end) return seg[node] = arr[start];

	int mid = (start + end) / 2;
	return seg[node] = (init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end)) % MOD;
}

ll update(int node, int start, int end, int idx, ll n) // idx번째 수를 n으로 갱신
{
	if (idx < start || end < idx) return seg[node];

	if (start == end) return seg[node] = n;

	int mid = (start + end) / 2;
	return seg[node] = (update(node * 2, start, mid, idx, n) *
		update(node * 2 + 1, mid + 1, end, idx, n)) % MOD;
}

ll get(int node, int start, int end, int left, int right)
{
	if (right < start || left > end) return 1;
	if (left <= start && end <= right) return seg[node];

	int mid = (start + end) / 2;
	return (get(node * 2, start, mid, left, right) * get(node * 2 + 1, mid + 1, end, left, right)) % MOD;
}

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) scanf("%d", arr + i);

	init(1, 1, N);
	int a, b, c;
	for (int i = 1; i <= M + K; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) update(1, 1, N, b, c);
		else printf("%lld\n", get(1, 1, N, b, c));
	}

	return 0;
}