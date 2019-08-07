#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

int n, m, k;
struct segtree {
	ll t[1 << 21], lz[1 << 21];
	int siz;
	void init()
	{
		for (siz = 1; siz <= n; siz <<= 1);
		for (int i = 1; i <= n; i++) cin >> t[siz + i];
		for (int i = siz - 1; i; i--) t[i] = t[2 * i] + t[2 * i + 1];
	}

	void update_lazy(int l, int r, int x)
	{
		t[x] += (r - l) * lz[x];
		if (r - l != 1)
		{
			lz[2 * x] += lz[x];
			lz[2 * x + 1] += lz[x];
		}
		lz[x] = 0;
	}

	void update(int s, int e, int l, int r, int x, ll v)
	{
		update_lazy(l, r, x);
		if (e <= l || r <= s) return;
		if (s <= l && r <= e)
		{
			lz[x] += v;
			update_lazy(l, r, x);
			return;
		}
		int m = (l + r) >> 1;
		update(s, e, l, m, 2 * x, v);
		update(s, e, m, r, 2 * x + 1, v);
		t[x] = t[2 * x] + t[2 * x + 1];
	}

	ll sum(int s, int e, int l, int r, int x)
	{
		update_lazy(l, r, x);
		if (e <= l || r <= s) return 0;
		if (s <= l && r <= e)
		{
			return t[x];
		}
		int m = (l + r) >> 1;
		return sum(s, e, l, m, 2 * x) + sum(s, e, m, r, 2 * x + 1);
	}
};
segtree seg;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	seg.init();
	for (int i = 0; i<m + k; i++)
	{
		int ty, s, e, v;
		cin >> ty;
		if (ty == 1)
		{
			cin >> s >> e >> v;
			seg.update(s, e + 1, 0, seg.siz, 1, v);
		}
		else
		{
			cin >> s >> e;
			cout << seg.sum(s, e + 1, 0, seg.siz, 1) << '\n';
		}
	}
}