#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

int N;
int wine[10000 + 5];
int D[10000 + 5][2]; // D[i][0] : i번째 와인을 마시지 않음, [1] : i번째 와인을 마심

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &wine[i]);

	memset(D, -1, sizeof(D));
	D[0][0] = D[0][1] = 0;
	D[1][0] = 0, D[1][1] = wine[1];

	for (int i = 2; i <= N; i++)
	{
		D[i][0] = max(D[i - 1][0], D[i - 1][1]);
		D[i][1] = max(D[i - 1][0], D[i - 2][0] + wine[i - 1]) + wine[i];
	}

	printf("%d", max(D[N][0], D[N][1]));

	return 0;
}