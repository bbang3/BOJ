#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;
typedef long long ll;

int N, M, K, M;
vector<ll> seg;
vector<ll> arr;

ll init(int node, int nodeLeft, int nodeRight) // (1, 1, N) 고정
{
	if (nodeLeft == nodeRight) return seg[node] = arr[nodeLeft];
	
	int mid = (nodeLeft + nodeRight) / 2;
	return seg[node] = init(node * 2, nodeLeft, mid) + init(node * 2 + 1, mid + 1, nodeRight);
}

void update(int node, int nodeLeft, int nodeRight, int idx, ll diff) // (1, 1, N, 바꿀 인덱스, 증감량)
{
	if (idx < nodeLeft || idx > nodeRight) return;

	seg[node] += diff;
	if (nodeLeft == nodeRight) return;

	int mid = (nodeLeft + nodeRight) / 2;
	update(node * 2, nodeLeft, mid, idx, diff);
	update(node * 2 + 1, mid + 1, nodeRight, idx, diff);
}

ll sum(int node, int nodeLeft, int nodeRight, int left, int right) // [left, right] 구간 합 반환
{
	if (right < nodeLeft || left > nodeRight) return 0;
	if (left <= nodeLeft && nodeRight <= right) return seg[node];

	int mid = (nodeLeft + nodeRight) / 2;
	return sum(node * 2, nodeLeft, mid, left, right) + sum(node * 2 + 1, mid + 1, nodeRight, left, right);
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	arr.resize(N + 2);
	for (int i = 1; i <= N; i++)
	{
		ll n;
		scanf("%lld", &n);
		arr[i] = n;
	}
	seg.resize(4 * N + 100);
	init(1, 1, N);
	M = M + K;
	while (M--)
	{
		int q, b, c;
		scanf("%d %d %d", &q, &b	, &c);
		if (q == 1)
		{
			ll diff = c - arr[b];
			arr[b] = c;
			update(1, 1, N, b, diff);
		}
		else
		{
			ll s = sum(1, 1, N, b, c);
			printf("%lld\n", s);
		}
	}

	return 0;
}