#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
char arr[51][51];
int visited[51][51];
int direction[2][2] = { {1,0}, {0,1}}; // 1)세로방향 2)가로방향
int N;
int num;
bool safe(int i, int j)
{
	return i >= 0 && i < N && j >= 0 && j < N;
}

int check(int i, int j, char shape, int di, int dj)
{
	visited[i][j] = 1; num++;
	if (safe(i + di, j + dj) && !visited[i + di][j + dj] && arr[i + di][j + dj] == shape)
		check(i + di, j + dj, shape, di, dj);
	if (safe(i - di, j - dj) && !visited[i - di][j - dj] && arr[i - di][j - dj] == shape)
		check(i - di, j - dj, shape, di, dj);
	return num;
}
int f()
{
	int M = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (safe(i + 1, j))q
			{
				cnt = 0;
				for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) visited[i][j] = 0;
				std::swap(arr[i][j], arr[i + 1][j]);
				M = std::max(M, check(i, j, arr[i][j],direction[0][0],direction[0][1]));
				cnt = 0;
				M = std::max(M, check(i, j, arr[i][j], direction[1][0], direction[1][1]));
				std::swap(arr[i][j], arr[i + 1][j]);
			}
			if (safe(i - 1, j))
			{
				cnt = 0;
				for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) visited[i][j] = 0;
				std::swap(arr[i][j], arr[i - 1][j]);
				M = std::max(M, check(i, j, arr[i][j], direction[0][0], direction[0][1]));
				M = std::max(M, check(i, j, arr[i][j], direction[1][0], direction[1][1]));
				std::swap(arr[i][j], arr[i - 1][j]);
			}
			if (safe(i, j + 1))
			{
				cnt = 0;
				for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) visited[i][j] = 0;
				std::swap(arr[i][j], arr[i][j + 1]);
				M = std::max(M, check(i, j, arr[i][j], direction[0][0], direction[0][1]));
				M = std::max(M, check(i, j, arr[i][j], direction[1][0], direction[1][1]));
				std::swap(arr[i][j], arr[i][j + 1]);
			}
			if (safe(i, j - 1))
			{
				cnt = 0;
				for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) visited[i][j] = 0;
				std::swap(arr[i][j], arr[i][j - 1]);
				M = std::max(M, check(i, j, arr[i][j], direction[0][0], direction[0][1]));
				M = std::max(M, check(i, j, arr[i][j], direction[1][0], direction[1][1]));
				std::swap(arr[i][j], arr[i][j - 1]);
			}
			printf("M : %d\n", M);
		}
	return M;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%s", arr[i]);
	printf("%d", f());
}