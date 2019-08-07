#include <cstdio>
#include <algorithm>
using namespace std;

int cnt(long long n, int k) // n!에 들어 있는 소인수 k의 개수
{
	int cnt = 0;
	while (n > 0)
	{
		n /= k;
		cnt += n;
	}
	return cnt;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	int two, five;
	two = cnt(N, 2) - cnt(M, 2) - cnt(N - M, 2);
	five = cnt(N, 5) - cnt(M, 5) - cnt(N - M, 5);
	printf("%d", min(two, five));

	return 0;
}