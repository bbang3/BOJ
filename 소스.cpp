#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int T, M, N, x, y;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d %d", &M, &N, &x, &y);
		if (x >= M && y > -N)
		{
			puts("-1");
			continue;
		}
	}
	return 0;
}