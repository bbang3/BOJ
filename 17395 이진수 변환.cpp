#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll x;
int N, cnt = 0;
void count(ll n)
{
	while (n > 0)
	{
		cnt += n & 1;
		n >>= 1;
	}
}

ll f(ll n)
{
	ll ret = 1;
	for (ret = 1; ret <= n; ret <<= 1);
	return ret >> 1;
}

int main()
{
	scanf("%lld %d", &x, &N);
	count(x);
	if (cnt < N)
	{
		printf("-1");
		return 0;
	}
	N--;
	while (N--)
	{
		x -= f(x);
		printf("%lld ", x);
	}
	printf("%d", 0);

	return 0;
}