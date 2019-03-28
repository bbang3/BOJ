#include <cstdio>
#include <algorithm>
using namespace std;

int T[20], P[20];
int N, ans;
// f(i, j) : i번째 날에 얻을 수 있는 최대 이익
void f(int curday, int curmoney) // curday날에 얻을 수 있는 최대 이익을 구한다.
{
	if (curday > N)
	{
		if (curday == N + 1)
		{
			//printf("%d\n", curmoney);
			ans = max(ans, curmoney);
		}
		return;
	}
	f(curday + 1, curmoney);
	f(curday + T[curday], curmoney + P[curday]);
}

int f(int curday)
{
	if (curday > N)
	{
		if (curday == N + 1) return 0;
		return -987654321;
	}
	return max(f(curday + 1), f(curday + T[curday]) + P[curday]);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) 
		scanf("%d %d", &T[i], &P[i]);
	printf("%d", f(1));
	//f(1, 0);
	//printf("%d", ans);
	return 0;
}