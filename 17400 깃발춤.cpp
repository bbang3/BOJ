#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;

const int MN = 3 * 1e5 + 5;
int N, Q;
ll arr[MN];
ll odd[5 * MN], even[5 * MN];
int sz;

void init(int n)
{
	for (sz = 1; sz < n; sz <<= 1);
}

void update(int pos, ll diff, ll tree[])
{
	while (pos <= sz)
	{
		tree[pos] += diff;
		pos += (pos & -pos);
	}
}

ll sum(int pos, ll tree[])
{
	ll sum = 0;
	while (pos)
	{
		sum += tree[pos];
		pos -= (pos & -pos);
	}
	return sum;
}

int main()
{
	scanf("%d %d", &N, &Q);
	init(N);
	for (int i = 1; i <= N; i++) scanf("%lld", &arr[i]);
	for (int i = 1; i <= N; i++)
	{
		if (i % 2 == 1) update(i, arr[i], odd);
		else update(i, arr[i], even);
	}

	while (Q--)
	{
		int opt, a, b;
		scanf("%d %d %d", &opt, &a, &b);
		if (opt == 1)
		{
			ll s1, s2;
			s1 = sum(b, odd) - sum(a - 1, odd);
			s2 = sum(b, even) - sum(a - 1, even);
			printf("%lld\n", abs(s1 - s2));
		}
		else
		{
			if (a % 2 == 1) update(a, b, odd);
			else update(a, b, even);
		}
	}

	return 0;
}