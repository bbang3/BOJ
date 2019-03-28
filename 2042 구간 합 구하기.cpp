#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

int N, M, K, Q;
vector<long long> tree;
vector<long long> arr;

long long init(int node, int start, int end) // tree의 node번 노드의 값(=arr의 start~end 구간 합)을 반환
{
	if (start == end)
	{
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int idx, int node, int diff, int start, int end)
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
// 현재 node번 노드 탐색 중, start - end 구간 내에서 left - right 구간 합 구하기
long long sum(int node, int start, int end, int left, int right)
{
	if (right < start || left > end) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++)
	{
		long long n;
		scanf("%lld", &n);
		arr.push_back(n);
	}
	int h = (int)ceil(log2(N));
	tree.resize((1 << (h + 1)) - 1);
	init(1, 0, N-1);
	Q = M + K;
	while (Q--)
	{
		int q, b, c;
		scanf("%d %d %d", &q, &b, &c);
		if (q == 1)
		{
			b--;
			long long diff = c - arr[b];
			arr[b] = c;
			update(b, 1, diff, 0, N - 1);
		}
		else
		{
			b--; c--;
			long long s = sum(1, 0, N-1, b, c);
			printf("%lld\n", s);
		}
	}

	return 0;
}