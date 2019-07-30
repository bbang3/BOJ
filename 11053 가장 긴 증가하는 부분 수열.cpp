#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
int arr[1001];
int D[1001]; // dp[i] = i번째 요소로 시작하는 LIS 길이
int N;
int f(int start) {
	if (D[start] != -1) return D[start];
	D[start] = 1;
	for (int i = start + 1; i <= N; i++) {
		if (arr[i] > arr[start])
			D[start] = max(D[start], f(i) + 1);
	}
	return D[start];
}

int main()
{
	scanf("%d"	, &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	memset(D, -1, sizeof(D));
	
	int ans = -1;
	for (int i = 1; i <= N; i++)
		ans = max(ans, f(i));
	printf("%d", ans);
	return 0;
}