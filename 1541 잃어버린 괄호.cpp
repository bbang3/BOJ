#include <cstdio>
#include <algorithm>
using namespace std;

char str[100];
// 조건에 의해 -가 처음 등장한 이후부터는 모든 수를 빼버릴 수 있다.
int main()
{
	scanf("%s", str);
	int temp = 0, ans = 0;
	bool first = true, minus = false;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			temp = temp * 10 + str[i] - '0';
		else
		{
			if (minus && !first) ans -= temp;
			else ans += temp;

			temp = 0;
			if (str[i] == '-') minus = true;
			if (first) first = false;
		}
	}
	minus ? ans -= temp : ans += temp;
	printf("%d", ans);
	return 0;
}