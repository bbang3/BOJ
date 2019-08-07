#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;

typedef long long ll;
const int MN = 1e6 + 5;

int N, M, K, Q, sz;
ll tree[4 * MN], arr[MN];

void init(int n)
{
	for (sz = 1; sz <= n; sz <<= 1);
	for (int i = 1; i <= n; i++) tree[i + sz] = arr[i];
	for (int i = sz - 1; i >= 1; i--)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

void update(int pos, ll diff)
{
	pos += sz;
	while (pos > 0)
	{
		tree[pos] += diff;
		pos >>= 1;
	}
}

ll sum(int l, int r) // [left, right] 구간 합 반환
{
	l += sz, r += sz;
	ll ret = 0;
	while (l < r)
	{
		if (l % 2 == 1) ret += tree[l++];
		if (r % 2 == 0) ret += tree[r--];
		l >>= 1, r >>= 1;
	}
	if (l == r) ret += tree[l];
	return ret;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) scanf("%lld", arr + i);

	init(N);
	Q = M + K;
	while (Q--)
	{
		int q, b, c;
		scanf("%d %d %d", &q, &b, &c);
		if (q == 1)
		{
			update(b, c - arr[b]);
			arr[b] = c;
		}
		else
		{
			printf("%lld\n", sum(b, c));
		}
	}

	return 0;
}