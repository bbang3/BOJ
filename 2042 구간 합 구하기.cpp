#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

int N, M, K, M;
vector<long long> seg;
vector<long long> arr;

long long init(int node, int start, int end) // (1, 1, N) 고정
{
	if (start == end) return seg[node] = arr[start];
	
	int mid = (start + end) / 2;
	return seg[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int idx, long long diff) // (1, 1, N, 바꿀 인덱스, 증감량)
{
	if (idx < start || idx > end) return;

	seg[node] += diff;
	if (start == end) return;

	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, diff);
	update(node * 2 + 1, mid + 1, end, idx, diff);
}

long long sum(int node, int start, int end, int left, int right) // [left, right] 구간 합 반환
{
	if (right < start || left > end) return 0;
	if (left <= start && end <= right) return seg[node];

	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	arr.resize(N + 2);
	for (int i = 1; i <= N; i++)
	{
		long long n;
		scanf("%lld", &n);
		arr[i] = n;
	}
	seg.resize(4 * N + 100);
	init(1, 1, N);
	M = M + K;
	while (M--)
	{
		int q, b, c;
		scanf("%d %d %d", &q, &b, &c);
		if (q == 1)
		{
			long long diff = c - arr[b];
			arr[b] = c;
			update(1, 1, N, b, diff);
		}
		else
		{
			long long s = sum(1, 1, N, b, c);
			printf("%lld\n", s);
		}
	}

	return 0;
}