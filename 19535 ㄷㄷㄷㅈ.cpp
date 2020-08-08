#include <bits/stdc++.h>
using namespace std;

// 루트 고정 아이디어
const int MN = 3e5 + 5;
typedef long long ll;

int N;
vector<int> G[MN];
ll dcnt = 0, gcnt = 0;

void dfs(int cur, int par, int depth)
{
	ll childcnt = par == -1 ? G[cur].size() : G[cur].size() - 1;
	if (depth >= 2) dcnt += childcnt;
	if (childcnt >= 3) gcnt += childcnt * (childcnt - 1) * (childcnt - 2) / 6;
	if (depth >= 1 && childcnt >= 2) gcnt += childcnt * (childcnt - 1) / 2;

	for (int next : G[cur])
	{
		if (next == par) continue;
		ll cchildcnt = G[next].size() - 1;
		if (cchildcnt >= 1) dcnt += cchildcnt * (childcnt - 1);

		dfs(next, cur, depth + 1);
	}
}

int main()
{
	scanf("%d", &N);
	int a, b;
	for (int i = 1; i <= N - 1; i++)
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1, -1, 0);
	//printf("%lld %lld\n", dcnt, gcnt);

	if (dcnt > gcnt * 3) puts("D");
	else if (dcnt < gcnt * 3) puts("G");
	else puts("DUDUDUNGA");

	return 0;
}