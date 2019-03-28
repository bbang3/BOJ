#include <cstdio>

const int MM = 100 + 5;
int N, I, M;
int X[MM], Y[MM];
int main()
{
	scanf("%d %d %d", &N, &I, &M);

	for (int i = 1; i <= M; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		X[i] = x, Y[i] = y;
	}

	int ans = 0;
	for (int i = 1; i <= M; i++)
	{
		//for (int j = 1; j <= M; j++)
		{
			int startx = X[i], starty = Y[i];

			for (int k = 1; k <= I / 2; k++)
			{
				int endx = startx + k, endy = starty + (I / 2 - k);

				int cnt = 0;
				for (int n = 1; n <= M; n++)
				{
					int curx = X[n], cury = Y[n];
					if (curx >= startx && curx <= endx && cury >= starty && cury <= endy)
						cnt++;
				}
				ans = cnt > ans ? cnt : ans;
			}
		}
	}
	printf("%d", ans);

	return 0;
}