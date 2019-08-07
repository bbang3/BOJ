#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 1e5 + 5;
int tree[4 * MN], lazy[4 * MN];

void propagate(int node, int s, int e)
{
	if (lazy[node] == 0) return;

	tree[node] = (e - s + 1) - tree[node]; // 구간 길이 - 켜진 스위치 개수
	if (s != e)
	{
		int mid = (s + e) / 2;
		lazy[node * 2] ^= 1;
		lazy[node * 2 + 1] ^= 1;
	}
	lazy[node] = 0;
}

void update(int node, int s, int e, int l, int r) // [l, r] 구간에 XOR
{
	propagate(node, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r)
	{
		lazy[node] ^= 1;
		propagate(node, s, e);
		return;
	}
	int m = (s + e) / 2;
	update(node * 2, s, m, l, r);
	update(node * 2 + 1, m + 1, e, l, r);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int sum(int node, int s, int e, int l, int r)
{
	propagate(node, s, e);
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return tree[node];
	int mid = (s + e) / 2;
	return sum(node * 2, s, mid, l, r) + sum(node * 2 + 1, mid + 1, e, l, r);
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	while (M--)
	{
		int o, s, t;
		scanf("%d %d %d", &o, &s, &t);
		if (!o)
		{
			update(1, 1, N, s, t);
		}
		else
		{
			printf("%d\n", sum(1, 1, N, s, t));
		}
	}
	return 0;
}