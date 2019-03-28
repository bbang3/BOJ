#include <cstdio>
#include <algorithm>
using namespace std;
int arr[100005];

int f(int l, int r)
{
	if (l == r) return arr[l];
	int mid = (l + r) / 2;
	int ans = 0;
	ans = max(ans, f(l, mid));
	ans = max(ans, f(mid + 1, r));

	int le = mid, ri = mid, curh = arr[mid];
	ans = max(ans, arr[mid]);
	while (le > l || ri < r)
	{
		if (le > l && (ri == r || arr[le - 1] > arr[ri + 1]))
			curh = min(arr[le - 1], curh), le--;
		else curh = min(arr[ri + 1], curh), ri++;

		ans = max(ans, curh * (ri - le + 1));
	}
	return ans;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", arr + i);
	printf("%d", f(1, N));

	return 0;
}