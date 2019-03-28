#include <cstdio>
#include <algorithm>
using namespace std;
int N;
long double T;
long long x[50001];
long long v[50001];
int main()
{
	scanf("%d %Lf", &N, &T);
	for (int i = 1; i <= N; i++) scanf("%lld", x + i);
	for (int i = 1; i <= N; i++) scanf("%lld", v + i);

	if (N == 1) { puts("1"); return 0; }
	long double a = x[1] - v[1] * T, b = x[1] + v[1] * T;
	long double c, d;
	for (int i = 2; i <= N; i++)
	{
		c = x[i] - v[i] * T, d = x[i] + v[i] * T;

		a = max(a, c);
		b = min(b, d);
	}
	if (a - b > 1e-8)
	{
		puts("0");
		return 0;
	}
	puts("1");
	return 0;
}