#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MN = 1e5;
int minfact[MN + 5] = { -1, -1, 0 };
int cnt[MN + 5];

void init()
{
	for (int i = 2; i <= MN; i++)
		minfact[i] = i;
	for (int i = 2; i * i <= MN; i++)
		if (minfact[i] == i)
			for (int j = i * i; j <= MN; j += i)
				if (minfact[j] == j) minfact[j] = i;
}

void factorize(int n)
{
	memset(cnt, 0, sizeof(cnt));

	while (n > 1)
	{
		cnt[minfact[n]]++;
		n /= minfact[n];
	}
	for (int i = 2; i <= MN; i++)
		if (cnt[i] != 0) printf("%d %d\n", i, cnt[i]);

	return;
}

int main()
{
	int T, n;
	scanf("%d", &T);

	init();
	while (T--)
	{
		scanf("%d", &n);
		factorize(n);
	}

	return 0;
}