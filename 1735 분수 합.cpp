#include <cstdio>
#include <algorithm>
int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);

	int n1 = a*d + b*c, n2 = b*d;
	int g = gcd(n1, n2);
	printf("%d %d", n1 / g, n2 / g);

	return 0;
}