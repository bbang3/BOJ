#include <cstdio>
#include <math.h>
#include <algorithm>
#define min(a,b) (a) < (b) ? (a) : (b)
using namespace std;

bool cantuse[10];
int main()
{
	int N;
	int b, c, ans;
	scanf("%d", &N);
	scanf("%d", &c);
	for (int i = 1; i <= c; i++) scanf("%d", &b), cantuse[b] = true;

	ans = abs(N - 100);
	if (!cantuse[0]) // 채널 '0'으로 갈 경우를 따로 계산
	{
		ans = min(ans, abs(N-0) + 1);
	}
	for (int curnum = 1; curnum <= 1000000; curnum++)
	{
		int temp = curnum, cnt = 0;
		bool canmake = true;

		while(temp > 0) // 자릿수 계산(특정 채널로 가기 위해 버튼 누르는 횟수)
		{
			if (cantuse[temp % 10])
			{
				canmake = false;
				break;
			}
			temp /= 10;
			cnt++;
		}

		if (canmake) // 그 채널로 갈 수 있다면
		{
			ans = min(ans, abs(curnum - N) + cnt); // 채널로 갈 때 누른 횟수 + 플러스마이너스 버튼 횟수
		}
		
	}
	printf("%d", ans);
	return 0;
}