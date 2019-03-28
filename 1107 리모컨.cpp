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
	if (!cantuse[0]) // ä�� '0'���� �� ��츦 ���� ���
	{
		ans = min(ans, abs(N-0) + 1);
	}
	for (int curnum = 1; curnum <= 1000000; curnum++)
	{
		int temp = curnum, cnt = 0;
		bool canmake = true;

		while(temp > 0) // �ڸ��� ���(Ư�� ä�η� ���� ���� ��ư ������ Ƚ��)
		{
			if (cantuse[temp % 10])
			{
				canmake = false;
				break;
			}
			temp /= 10;
			cnt++;
		}

		if (canmake) // �� ä�η� �� �� �ִٸ�
		{
			ans = min(ans, abs(curnum - N) + cnt); // ä�η� �� �� ���� Ƚ�� + �÷������̳ʽ� ��ư Ƚ��
		}
		
	}
	printf("%d", ans);
	return 0;
}