#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int fibo[100] = { 0, 1, };
vector<int> V;
void f(int curidx, int curn)
{
	if (curidx == 0)
	{
		if (curn == 0)
		{
			sort(V.begin(), V.end());
			for (int a : V) printf("%d ", a);
		}
		return;
	}
	if (curn >= fibo[curidx])
	{
		V.push_back(fibo[curidx]);
		f(curidx - 1, curn - fibo[curidx]);
	}
	else f(curidx - 1, curn);

	return;
}

int main()
{
	int T;
	scanf("%d", &T);
	int i;
	for (i = 2; ; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		if (fibo[i] > 1000000000) break;
	}
	while (T--)
	{
		int n;
		scanf("%d", &n);

		V.clear();
		f(i, n);
		puts("");
	}

	return 0;
}