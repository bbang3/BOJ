#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long ll;
struct pos
{
	int x; int y;
};
bool cmp(pos a, pos b) { return a.y == b.y ? a.x > b.x : a.y < b.y; }
bool cmp2(pos a, pos b) { return a.x == b.x ? a.y < b.y : a.x > b.x; }

const int MN = 75000 + 5;
pos P[MN], Q[MN];
ll tree[4 * MN];
int sz;

void init(int n) { for (sz = 1; sz <= n; sz <<= 1); }
void update(int pos)
{
	while (pos <= sz)
	{
		tree[pos]++;
		pos += (pos & -pos);
	}
}
ll sum(int pos)
{
	ll ret = 0;
	while (pos > 0)
	{
		ret += tree[pos];
		pos -= (pos & -pos);
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(tree, 0, sizeof(tree));
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) scanf("%d %d", &P[i].x, &P[i].y);

		sort(P + 1, P + N + 1, cmp); // y좌표 오름차순(같으면 x좌표 내림차순)
		for (int i = 1; i <= N; i++) { Q[i] = { P[i].x, i }; } // y좌표 좌표압축
		sort(Q + 1, Q + N + 1, cmp2); // x좌표 내림차순(같으면 y좌표 오름차순)
		init(N);
		ll ans = 0;
		for (int i = 1; i <= N; i++)
		{
			ans += sum(Q[i].y - 1); // inversion 개수 세기
			update(Q[i].y);
		}
		printf("%lld\n", ans);
	}

	return 0;
}