#include <cstdio>
#include <algorithm>
using namespace std;

struct query
{
	int num, strike, ball;
};
query Q[100 + 5];
int N;

bool check(int i, int j, int k)
{
	for (int t = 1; t <= N; t++)
	{
		int stcnt = 0, ballcnt = 0;

		if (Q[t].num / 100 == i) stcnt++;
		if (Q[t].num / 10 % 10 == j) stcnt++;
		if (Q[t].num % 10 == k) stcnt++;

		if (Q[t].num / 100 == j || Q[t].num / 100 == k) ballcnt++;
		if (Q[t].num / 10 % 10 == i || Q[t].num / 10 % 10 == k) ballcnt++;
		if (Q[t].num % 10 == i || Q[t].num % 10 == j) ballcnt++;

		if (!(stcnt == Q[t].strike && ballcnt == Q[t].ball)) return false;
	}
	return true;
}


int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d %d", &Q[i].num, &Q[i].strike, &Q[i].ball);

	int ans = 0;
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			for (int k = 1; k <= 9; k++)
			{
				if (i == j || j == k || k == i) continue;
				ans += check(i, j, k);
			}

	printf("%d", ans);
	return 0;
}