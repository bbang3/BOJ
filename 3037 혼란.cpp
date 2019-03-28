#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

const int MOD = 1e9 + 7;
long long D[1000 + 5][10000 + 5]; // D[i][j] : 길이가 i이고, 혼란도 j인 수열의 개수
int main()
{
	int N, C;
	scanf("%d %d", &N, &C);

	D[0][0] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= C; j++)
		{
			if (j - i < 0) D[i][j] = (D[i][j - 1] + D[i - 1][j]) % MOD;
			else
			{
				long long d = (D[i][j - 1] + D[i - 1][j] - D[i - 1][j - i]);
				if (d < 0) d = MOD + d;
				D[i][j] = d % MOD;
			}
		}
	}
	printf("%lld", D[N][C]);
	return 0;
}