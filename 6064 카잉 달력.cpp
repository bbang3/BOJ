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
		
		bool chk = false;
		for (int i = 0; i <= M; i++)
			if ((y - x + i * N) % M == 0)
			{
				chk = true;
				printf("%d\n", y + i * N);
				break;
			}

		if (!chk) puts("-1");
	}
	return 0;
}