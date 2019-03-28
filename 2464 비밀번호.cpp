#include <cstdio>

int get_2(long long num)
{
	int ret = 0;
	while (num > 0)
	{
		ret += num % 2;
		num /= 2;
	}
	return ret;
}

int main()
{
	long long N;
	scanf("%lld", &N);

	int acnt = get_2(N);
	for (int i = N - 1; i >= 0; i--)
		if (get_2(i) == acnt) printf("%lld", i);
	for (int i = N + 1; i >= 0; i--)
		if (get_2(i) == acnt) printf("%lld", i);

	return 0;
}