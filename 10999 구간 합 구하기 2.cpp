#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

int N, M, S, M;
vector<long long> seg;
vector<long long> arr;
vector<long long> lazy;

long long init(int node, int start, int end) // (1, 1, N) 고정
{
	if (start == end) return seg[node] = arr[start];

	int mid = (start + end) / 2;
	return seg[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int idx, long long diff)
{
	if (idx < start || idx > end) return;

	seg[node] += diff;
	if (start == end) return;

	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, diff);
	update(node * 2 + 1, mid + 1, end, idx, diff);
}

void update_lazy(int node, int start, int end)
{
	if (lazy[node] == 0) return;

	seg[node] += (end - start + 1) * lazy[node];
	if (start != end)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update_range(int node, int start, int end, int left, int right, long long diff) // [left, right] 구간에 diff만큼 더한다.
{
	update_lazy(node, start, end);
	if (right < start || left > end) return;
	if (left <= start && end <= right)
	{
		seg[node] += (end - start + 1) * diff;
		if(start != end)
		{
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	int mid = (start + end) / 2;
	update_range(node * 2, start, mid, left, right, diff);
	update_range(node * 2 + 1, mid + 1, end, left, right, diff);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

// 현재 node번 노드 탐색 중, start - end 구간 내에서 left - right 구간 합 구하기
long long sum(int node, int start, int end, int left, int right)
{
	update_lazy(node, start, end);
	if (right < start || left > end) return 0;
	if (left <= start && end <= right) return seg[node];

	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	scanf("%d %d %d", &N, &M, &S);
	arr.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &arr[i]);
	}
	int size = (1 << ((int)ceil(log2(N))) + 1) - 1;
	seg.resize(size); lazy.resize(size);
	init(1, 1, N);
	M = M + S;
	while (M--)
	{
		int q;
		scanf("%d", &q);
		if (q == 1)
		{
			int b, c; long long d;
			scanf("%d %d %lld", &b, &c, &d);
			update_range(1, 1, N, b, c, d);
		}
		else
		{
			int b, c;
			scanf("%d %d", &b, &c);
			long long s = sum(1, 1, N, b, c);
			printf("%lld\n", s);
		}
	}

	return 0;
}