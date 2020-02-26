#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MPOS = 2e5 + 1;
const ll MOD = 1e9 + 7;
struct segTree
{
	ll cnt[4 * MPOS];
	ll pos[4 * MPOS];

	void update(int node, int start, int end, int idx, ll diff) // (1, 1, N, 바꿀 인덱스, 증감량)
	{
		if (idx < start || idx > end) return;

		cnt[node]++;
		pos[node] += diff;
		if (start == end) return;

		int mid = (start + end) / 2;
		update(node * 2, start, mid, idx, diff);
		update(node * 2 + 1, mid + 1, end, idx, diff);
	}

	ll sum_cnt(int node, int start, int end, int left, int right) // [left, right] 구간 합 반환
	{
		if (right < start || left > end) return 0;
		if (left <= start && end <= right) return cnt[node];

		int mid = (start + end) / 2;
		return sum_cnt(node * 2, start, mid, left, right) + sum_cnt(node * 2 + 1, mid + 1, end, left, right);
	}

	ll sum_pos(int node, int start, int end, int left, int right) // [left, right] 구간 합 반환
	{
		if (right < start || left > end) return 0;
		if (left <= start && end <= right) return pos[node];

		int mid = (start + end) / 2;
		return sum_pos(node * 2, start, mid, left, right) + sum_pos(node * 2 + 1, mid + 1, end, left, right);
	}

};

segTree sg;
int main()
{
	int N;
	scanf("%d", &N);

	ll ans = 1;
	int x;
	scanf("%d", &x); x++;
	sg.update(1, 1, MPOS, x, x);

	for (int i = 2; i <= N; i++)
	{
		scanf("%d", &x); x++;
		ll lcnt = sg.sum_cnt(1, 1, MPOS, 1, x - 1), lsum = sg.sum_pos(1, 1, MPOS, 1, x - 1);
		ll rcnt = sg.sum_cnt(1, 1, MPOS, x + 1, MPOS), rsum = sg.sum_pos(1, 1, MPOS, x + 1, MPOS);
		ll s = ((lcnt * x - lsum) + (rsum - rcnt * x)) % MOD; // s 자체도 long long 범위를 벗어날 수 있음
		ans = (ans * s) % MOD;
		//printf("%lld %lld %lld %lld %lld\n", lcnt, lsum, rcnt, rsum, s);

		sg.update(1, 1, MPOS, x, x);
	}
	printf("%lld", ans);
	return 0;
}