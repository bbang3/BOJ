#include <cstdio>
#include <algorithm>
using namespace std;

bool visit[30];
int N, x, y;
long long ans = 0;
void f(int n, int exc)
{
	if (n == exc)
	{
		f(n + 1, exc);1
		return;
	}
	if (n == N + 1)
	{
		ans++;
		return;
	}
	for (int i = 1; i + n + 1 <= 2 * N; i++)
	{
		if (!visit[i] && !visit[i + n + 1])
		{
			visit[i] = visit[i + n + 1] = true;
			f(n + 1, exc);
			visit[i] = visit[i + n + 1] = false;
		}
	}
	return;
}

int main()
{

	return 0;
}