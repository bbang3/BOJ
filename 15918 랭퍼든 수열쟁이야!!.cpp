#include <cstdio>
#include <algorithm>
using namespace std;

bool chk[30];
int N, x, y;
long long ans = 0;
void f(int n, int exc)
{
	if (n == exc)
	{
		f(n + 1, exc);
		return;
	}
	if (n == N + 1)
	{
		ans++;
		return;
	}
	for (int i = 1; i + n + 1 <= 2 * N; i++)
	{
		if (!chk[i] && !chk[i + n + 1])
		{
			chk[i] = chk[i + n + 1] = true;
			f(n + 1, exc);
			chk[i] = chk[i + n + 1] = false;
		}
	}
	return;
}

int main()
{

	return 0;
}