#include <cstdio>
#include <algorithm>
using namespace std;
// fenwick tree를 이용한 방법은 중복 원소가 없어야 가능함.
struct S
{
	int idx; int n;
	bool operator < (S a) { return n > a.n; }
};

typedef long long ll;
const int MN = 5 * 1e5 + 5;
S arr[MN];
ll tree[4 * MN];
int sz;

void init(int n)
{
	for (sz = 1; sz <= n; sz <<= 1);
}

void update(int pos) // pos번 위치에 +1
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
	int N;
	scanf("%d", &N);
	init(N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i].n);
		arr[i].idx = i;
	}
	sort(arr + 1, arr + N + 1);
	
	ll ans = 0;
	for (int i = 1; i <= N; i++)
	{
		ans += sum(arr[i].idx - 1);
		update(arr[i].idx);
	}
	printf("%lld", ans);
	return 0;
}