#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

bool isprime[1000000 + 5];
int main()
{
	int M, N;
	scanf("%d %d", &M, &N);

	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;

	for (int i = 2; i * i <= N; i++)
		if (isprime[i])
			for (int j = i * i; j <= N; j += i)
				isprime[j] = false;

	for (int num = M; num <= N; num++)
		if (isprime[num])
			printf("%d\n", num);
	return 0;
}