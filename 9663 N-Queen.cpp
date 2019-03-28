#include <cstdio>

int N;
bool time[20][20];
int totallen = 0;

bool can(int i, int j)
{
	for (int k = 1; k <= N; k++)
	{
		if (time[i][k] || time[k][j])
			return false;
	}
	bool loop = true;
	for (int k = 1; loop; k++)
	{
		loop = false;
		if (i - k > 0 && j - k > 0)
		{
			loop = true;
			if (time[i - k][j - k]) return false;
		}
		if (i - k > 0 && j + k <= N)
		{
			loop = true;
			if (time[i - k][j + k]) return false;
		}
	}

	return true;
}

void f(int i, int j, int cnt) // (i,j) 위치에 퀸을 놓는 경우 검사
{
	if (cnt == N)
	{
		totallen++;
		return;
	}
	if (i > N) return;


	if (can(i, j))
	{
		time[i][j] = true;
		f(i + 1, 1, cnt + 1);
	}
	time[i][j] = false;
	if (j == N) return;
	f(i, j + 1, cnt);

	return;
}

int main()
{
	scanf("%d", &N);
	f(1, 1, 0);
	printf("%d", totallen);
	return 0;
}