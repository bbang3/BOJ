#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const int MN = 1e5 + 5;
int par[MN], in[MN], out[MN]; // [in[i], out[i]] : i를 루트로 하는 서브트리의 구간
int cnt = 0;
vector<int> G[MN];

void dfs(int n)
{
	in[n] = ++cnt;
	for (int next : G[n])
		dfs(next);
	out[n] = cnt;
}

ll tree[4 * MN], lazy[4 * MN];
int sz;

void init(int N)
{
	for (sz = 1; sz <= N; sz <<= 1);
}

void propagate(int node, int s, int e)
{
	if (lazy[node] == 0) return;
	tree[node] += (e - s + 1) * lazy[node];
	if (s != e)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}
// [l, r] 구간에 diff만큼 update
void update(int node, int s, int e, int l, int r, ll diff)
{
	propagate(node, s, e);
	if (l > e || r < s) return;
	if (l <= s && e <= r)
	{
		lazy[node] += diff;
		propagate(node, s, e);
		return;
	}
	int m = (s + e) / 2;
	update(node * 2, s, m, l, r, diff);
	update(node * 2 + 1, m + 1, e, l, r, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void print(int node, int s, int e, int target)
{
	propagate(node, s, e);
	if (target < s || e < target) return;
	if (s == target && e == target)
	{
		printf("%lld\n", tree[node]);
		return;
	}
	int m = (s + e) / 2;
	print(node * 2, s, m, target);
	print(node * 2 + 1, m + 1, e, target);
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &par[i]);
		if (par[i] != -1) G[par[i]].push_back(i);
	}
	init(N); dfs(1);
	while (M--)
	{
		int opt;
		scanf("%d", &opt);
		if (opt == 1)
		{
			int i, w;
			scanf("%d %d", &i, &w);
			update(1, 1, sz, in[i], out[i], w);
		}
		else
		{
			int n;
			scanf("%d", &n);
			print(1, 1, sz, in[n]);
		}
	}
	return 0;
}