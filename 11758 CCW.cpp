#include <iostream>
#include <algorithm>
using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
	int res = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
	if (res > 0) return 1;
	else if (res < 0) return -1;
	else return 0;
}

int main()
{
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	printf("%d", ccw(x1, y1, x2, y2, x3, y3));
	return 0;
}