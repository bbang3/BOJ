#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;

const int MN = 1e5 + 5;
int N;
long long Y[MN];
int main()
{		
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%lld", Y + i);
	long long k;
	scanf("%lld", &k);

	if (N == 1)
	{
		Y[1] == k ? puts("T") : puts("F");
		return 0;
	}
	for (int i = 2; i <= N; i++)
	{
		if ((Y[i - 1] >= (i - 1) * k && Y[i] <= i * k) 
			|| (Y[i - 1] <= (i - 1) * k && Y[i] >= i * k))
		{
			puts("T");
			return 0;
		}
	}
	puts("F");
	return 0;
}