#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

int N, M, K, Q;
vector<long long> tree;
vector<long long> arr;
vector<long long> lazy;

long long init(int node, int start, int end) // tree의 node번 노드의 값(=arr의 start~end 구간 합)을 반환
{
	if (start == end)
	{
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int idx, int node, long long diff, int start, int end)
{
	if (idx < start || idx > end) return;

	tree[node] += diff;
	if (start == end)
	{
		return;
	}
	int mid = (start + end) / 2;
	update(idx, node * 2, diff, start, mid);
	update(idx, node * 2 + 1, diff, mid + 1, end);
}

void update_lazy(int node, int start, int end)
{
	if (lazy[node] == 0) return;
	tree[node] += (end - start + 1) * lazy[node];
	if (start != end)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update_range(long long diff, int node, int start, int end, int left, int right)
{
	update_lazy(node, start, end);
	if (right < start || left > end) return;
	if (left <= start && end <= right)
	{
		tree[node] += (end - start + 1) * diff;
		if(start != end)
		{
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	int mid = (start + end) / 2;
	update_range(diff, node * 2, start, mid, left, right);
	update_range(diff, node * 2 + 1, mid + 1, end, left, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// 현재 node번 노드 탐색 중, start - end 구간 내에서 left - right 구간 합 구하기
long long sum(int node, int start, int end, int left, int right)
{
	update_lazy(node, start, end);
	if (right < start || left > end) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	arr.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &arr[i]);
	}
	int size = (1 << ((int)ceil(log2(N))) + 1) - 1;
	tree.resize(size); lazy.resize(size);
	init(1, 1, N);
	Q = M + K;
	while (Q--)
	{
		int q;
		scanf("%d", &q);
		if (q == 1)
		{
			int b, c; long long d;
			scanf("%d %d %lld", &b, &c, &d);
			update_range(d, 1, 1, N, b, c);
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