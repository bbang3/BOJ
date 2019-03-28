#include <cstdio>

int R, C;
char map[30][30];
bool time[30];
int totallen = 0;
void f(int i, int j, int cnt)
{
	if (time[map[i][j] - 'A']) return;
	if (i < 1 || i > R || j < 1 || j > C) return;
	totallen = cnt > totallen ? cnt : totallen;

	time[map[i][j] - 'A'] = true;
	f(i + 1, j, cnt + 1);
	f(i - 1, j, cnt + 1);
	f(i, j + 1, cnt + 1);
	f(i, j - 1, cnt + 1);
	time[map[i][j] - 'A'] = false;
}

int main()
{
	scanf("%d %d", &R, &C);

	for (int i = 1; i <= R; i++)
	{
		scanf("%s", map[i] + 1);
	}
	f(1, 1, 1);
	printf("%d", totallen);
	return 0;
}