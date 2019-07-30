#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	int x1, y1, r1, x2, y2, r2;
	while (T--)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		int d2 = (abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
		if (r1 == r2 && d2 == 0) puts("-1");
		else if ((r1 + r2) * (r1 + r2) == d2) puts("1"); // r1 + r2 = d -> 외접
		else if ((r1 + r2) * (r1 + r2) < d2) puts("0"); // r1 + r2 < d -> 만나지 않음
		else if (abs(r1 - r2) * abs(r1 - r2) == d2) puts("1"); // r1 - r2 == d -> 내접
		else if (abs(r1 - r2) * abs(r1 - r2) > d2) puts("0"); // r1 - r2 > d -> 한 원이 내부에 있음
		else puts("2");
	}
	return 0;
}