#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MN = 5e5 + 5;
int arr[MN], res[MN];
int N;
ll ans = 0;

void merge(int left, int right)
{
	int mid = (left + right) / 2;
	int i = left, j = mid + 1, idx = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j]) res[idx++] = arr[i++];
		else res[idx++] = arr[j++], ans += (mid - i + 1);
	}
	while (i <= mid) res[idx++] = arr[i++];
	while (j <= right) res[idx++] = arr[j++];
	for (int k = left; k <= right; k++) arr[k] = res[k];
}

void mergesort(int left, int right)
{
	if (left == right) return;

	int mid = (left + right) / 2;
	mergesort(left, mid);
	mergesort(mid + 1, right);
	merge(left, right);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", arr + i);

	mergesort(1, N);
	printf("%lld", ans);
	return 0;
}