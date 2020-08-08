#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 1e5 + 5;
const int MOD = 1e9;

struct edge
{
	int a;
	int b;
	int w;

	bool operator < (edge& b)
	{
		return w > b.w;
	}
};

vector<edge> edgeList;
int N, M;
int par[MN];
ll setsize[MN];

int find(int n)
{
	return par[n] == n ? n : par[n] = find(par[n]);
}

bool merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return false;

	if(a < b)
	{
		par[b] = a;
		setsize[a] += setsize[b];
	}
	else
	{
		par[a] = b;
		setsize[b] += setsize[a];
	}

	return true;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) par[i] = i, setsize[i] = 1;

	ll costSum = 0;
	edgeList.resize(M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &edgeList[i].a, &edgeList[i].b, &edgeList[i].w);
		costSum += edgeList[i].w;
	}
	sort(edgeList.begin(), edgeList.end());

	ll ans = 0;
	for (int i = 0; i < M; i++)
	{
		edge cur = edgeList[i];
		int a = find(cur.a), b = find(cur.b);
		ll asz = setsize[a], bsz = setsize[b];
		bool ok = merge(a, b);

		if (ok)
		{
			ll ret = (((asz * bsz) % MOD) * costSum) % MOD;
			ans = (ans + ret) % MOD;
		}
		costSum -= cur.w;
	}
	printf("%lld", ans);

	return 0;
}