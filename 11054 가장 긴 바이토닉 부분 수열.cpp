#include <cstdio>
#include <algorithm>
int N;
int arr[1005];
int A[1005], B[1005];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", arr + i);

	for (int i = 1; i <= N; i++)
	{
		int bi = N - i + 1;
		A[i] = B[bi] = 1;
		for (int j = 1; j < i; j++)
		{
			int bj = N - j + 1;
			if (arr[i] > arr[j])
				A[i] = std::max(A[j] + 1, A[i]);
			if (arr[bi] > arr[bj])
				B[bi] = std::max(B[bj] + 1, B[bi]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) ans = std::max(ans, A[i] + B[i] - 1);
	printf("%d", ans);
	return 0;
}