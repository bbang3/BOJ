#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MN = 1e6 + 5;

ll tree[4 * MN], arr[MN];
int sz;

void init(int n) // n개의 원소에 대한 트리의 배열 크기
{
	for (sz = 1; sz < n; sz <<= 1);
}

void update(int pos, ll diff) // pos번 위치에 diff만큼 추가
{
	while (pos <= sz)
	{
		tree[pos] += diff;
		pos += (pos & -pos);
	}
}

ll sum(int pos) // [1, pos] 구간 합
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
	int N, M, K, Q;
	scanf("%d %d %d", &N, &M, &K);
	Q = M + K;
	init(N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", arr + i);
		update(i, arr[i]);
	}
	while (Q--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1)
		{
			update(b, c - arr[b]);
			arr[b] = c;
		}
		else printf("%lld\n", sum(c) - sum(b - 1));
	}
	return 0;
}