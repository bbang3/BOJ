#include <cstdio>
#include <algorithm>
using namespace std;
char board[52][52];
int check(int a, int b) // (a,b) 위치에서 시작하는 8*8 체스판 검사
{

	char shape = 'B';
	int cnt1 = 0, cnt2 = 0;
	for (int i = a; i < a + 8; i++)
		for (int j = b; j < b + 8; j++)
		{
			if (board[i][j] != shape) cnt1++;
			if (j == b + 7) continue;
			if (shape == 'B') shape = 'W';
			else shape = 'B';
		}
	shape = 'W';
	for (int i = a; i < a + 8; i++)
		for (int j = b; j < b + 8; j++)
		{
			if (board[i][j] != shape) cnt2++;
			if (j == b + 7) continue;
			if (shape == 'B') shape = 'W';
			else shape = 'B';
		}
	return cnt1 < cnt2 ? cnt1 : cnt2;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", board[i]);

	int ans = 987654321;
	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			ans = min(ans, check(i, j));
		}
	}
	printf("%d", ans);
	return 0;
}