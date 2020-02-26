#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

struct frac
{
	ll a; ll b;

	frac() {}
	frac(ll a, ll b) : a(a), b(b) {}

	frac operator- (frac t)
	{
		ll rb = b / gcd(b, t.b) * t.b;
		ll ra = rb / b * a - rb / t.b * t.a;

		frac result = { ra, rb };
		return result;
	}

};

// x는 1/x < a/b를 만족하는 가장 큰 수
// -> x > b/a를 만족하는 가장 작은 수
void henry(frac input)
{
	ll x = 2;
	while (true)
	{
		if (input.a == 1) x = input.b;
		else x = (int)((double)input.b / input.a) + 1; 

		frac res = input - frac(1LL, x);
		if (res.a == 0) break;

		ll g = gcd(res.a, res.b);
		res.a = res.a / g;
		res.b = res.b / g;

		input = res;
	}
	printf("%lld\n", x);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		frac f;
		scanf("%lld %lld", &f.a, &f.b);
		henry(f);
	}

	return 0;
}