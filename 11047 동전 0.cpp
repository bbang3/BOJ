#include <cstdio>
#include <algorithm>
using namespace std;

// ���� ��ġ�� ���� ����̱� ������, �ִ��� ��ġ�� ū �ͺ��� ���� ���� �� �̵��̴�.
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