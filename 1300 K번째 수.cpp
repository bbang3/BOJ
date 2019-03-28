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

		int cnt = 0; // N*N �迭���� mid���� ���� ���� ������ ����.
		for (int i = 1; i <= N; i++) // i��° �࿡ ���Ͽ�
		{
			cnt += min(mid / i, N); // mid�� i��° ���� ��� ������ ū ��� N���� ���Ѵ�.
		}

		if (cnt < K) // mid���� ���� ���� k���� ���� ���(mid�� k��° ������ ū ���� ���)
 		{
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%d", left);

	return 0;
}