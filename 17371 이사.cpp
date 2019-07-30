#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;

struct pos { int x; int y; };
pos P[1000 + 5];

double getdist(pos a, pos b)
{
	return sqrt(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &P[i].x, &P[i].y);

	pos p = P[1];
	double minmax = 1234567;
	for (int i = 1; i <= N; i++)
	{
		double maxdist = 0;
		for (int j = 1; j <= N; j++)
			maxdist = max(maxdist, getdist(P[i], P[j]));

		if (maxdist < minmax)
		{
			minmax = maxdist;
			p = P[i];
		}
	}
	printf("%d %d", p.x, p.y);

	return 0;
}