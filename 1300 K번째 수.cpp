#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 1e5 + 5;
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	int left = 1, right = K, mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		int cnt = 0; // N*N 배열에서 mid보다 작은 수의 개수를 센다.
		for (int i = 1; i <= N; i++) // i번째 행에 대하여
		{
			cnt += min(mid / i, N); // mid가 i번째 행의 모든 수보다 큰 경우 N만을 더한다.
		}

		if (cnt < K) // mid보다 작은 수가 k보다 많을 경우(mid가 k번째 수보다 큰 수일 경우)
 		{
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%d", left);

	return 0;
}