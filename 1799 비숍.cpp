#include <cstdio>

int N;
bool can[15][15];
bool inv_ru[50];
int totallen = 0;


void f(int imj, int cnt)
{
	totallen = cnt > totallen ? cnt : totallen;
	if (N - imj + cnt <= totallen) return;
	if (imj >= N) return;

	f(imj + 1, cnt);
	for (int j = 1; j <= N; j++)
	{
		int i = imj + j;
		if (i < 1 || i > N) continue;

		if (can[i][j] && !inv_ru[i + j])
		{
			inv_ru[i + j] = true;
			f(imj + 1, cnt + 1);
			inv_ru[i + j] = false;
		}
	}

	return;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &can[i][j]);
	f(1 - N, 0);
	printf("%d", totallen);
	return 0;
}