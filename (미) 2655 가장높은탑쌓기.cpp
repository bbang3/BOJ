#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 100 + 5;
int N;

struct brick
{
	int idx;
	int s;
	int h;
	int w;

	brick() {}

	brick(int idx, int s, int h, int w) : idx(idx), s(s), h(h), w(w) {}
};

struct info
{
	brick bot;
	int h;

	info() {}
	info(brick bottom, int h) : bot(bottom), h(h) {}
};

brick B[MN];
info D[MN];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int s, h, w;
		scanf("%d %d %d", &s, &h, &w);
		B[i] = brick(i, s, h, w);
	}

	sort(B + 1, B + N + 1, [](brick a, brick b) {return a.w < b.w; });

	D[1] = info(B[1], B[1].h);
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (B[j].s < D[i].bot.s)
			{
				if(D[i].h < D[j].h + B[j].h)
			}
		}
	}
	return 0;
}