#include <cstdio>
#include <algorithm>
using namespace std;

struct info
{
	int s;
	int e;
	info() { s = 1005, e = 1005; }
	info(int s, int e) : s(s), e(e) {}

	bool operator < (const info &a)
	{
		return s < a.s;
	}
};
const int MN = 1000 + 5;
int N, M;
info T[MN];
int ans = 987654321;

void f(int curidx, int maxlen, int startday)
{
	if (curidx == M + 1)
	{
		maxlen = max(maxlen, N - startday + 1);
		ans = min(ans, maxlen);
		return;
	}
	if (T[curidx].s < startday) f(curidx + 1, maxlen, startday);
	else if (T[curidx].s - startday >= ans) f(curidx + 1, maxlen, startday);
	else
	{
		for (int i = curidx; i <= M; i++)
		{
			if (T[i].s - startday >= ans) continue;
			f(i + 1, max(maxlen, T[i].s - startday), T[i].e + 1);
		}
	}

	return;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= M; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		T[i] = info(s, e);
	}
	sort(T + 1, T + N + 1);

	f(1, 0, 1);
	printf("%d", ans);
	return 0;
}