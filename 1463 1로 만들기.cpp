#include <cstdio>
#include <algorithm>
using namespace std;
int D[1000001]; // 연산 횟수 저장

int f(int num)
{
	if (num == 1) return 0;
	if (D[num]) return D[num];

	int &ret = D[num];
	if (num % 3 == 0 && num % 2 == 0)
		ret = 1 + min(f(num / 3), f(num / 2));
	else if (num % 3 == 0)
		ret = 1 + min(f(num / 3), f(num - 1));
	else if (num % 2 == 0)
		ret = 1 + min(f(num / 2), f(num - 1));
	else ret = 1 + f(num - 1);

	return ret;
}

int main()
{
	int N;
	scanf("%d", &N);
	printf("%d", f(N));

	return 0;
}