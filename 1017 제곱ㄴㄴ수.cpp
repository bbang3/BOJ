#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
const int MN = 1e6;

vector<ll> primeList;
bool chk[MN + 5]; // [a, b] 범위에 대해서만 체크하면 됨 -> n - a의 형태로 저장

int main()
{
	for (ll i = 2; i <= MN; i++)
	{
		bool isPrime = false;
		for (ll j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				isPrime = true;
				break;
			}
		}
		if (!isPrime) primeList.push_back(i);
	}

	ll a, b;
	scanf("%lld %lld", &a, &b);
	for (ll p : primeList)
	{
		ll sq = p * p, start = a / sq * sq;
		if (sq > b) continue;
		for (ll n = start; n <= b; n += sq)
		{
			if (n < a) continue;
			chk[n - a] = true;
		}
	}

	int ans = 0;
	for (ll i = a; i <= b; i++)
		ans += !chk[i - a];

	printf("%d", ans);

	return 0;
}