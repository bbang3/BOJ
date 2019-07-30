#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int T, a, b, len;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &a, &b);
		len = b - a;
		int i = (int)sqrt(len);

		if (len == i * i)
			printf("%d\n", 2 * i - 1);
		else if (len <= i * (i + 1))
			printf("%d\n", 2 * i);
		else printf("%d\n", 2 * i + 1);
	}
	return 0;
}