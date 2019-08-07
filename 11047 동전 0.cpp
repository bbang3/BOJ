#include <cstdio>
#include <algorithm>
using namespace std;

// 동전 가치가 서로 배수이기 때문에, 최대한 가치가 큰 것부터 많이 쓰는 게 이득이다.
int main()
{
	int N, K, coin[15];
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%d", coin + i);
	
	int cnt = 0;
	for (int i = N; i >= 1; i--)
	{
		cnt += K / coin[i];
		K %= coin[i];
	}

	printf("%d", cnt);

	return 0;
}