#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct pos
{
	int x; int y; int idx;
	bool operator == (pos a) { return a.x == x && a.y == y && a.idx == idx; }
};
typedef long long ll;

int ccw(pos p1, pos p2, pos p3)
{
	ll res = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y);
	res -= p2.x * p1.y + p3.x * p2.y + p1.x * p3.y;
	if (res > 0) return 1;
	else if (res < 0) return -1;
	return 0;
}

int main()
{
	int C;
	scanf("%d", &C);
	while (C--)
	{
		int N;
		scanf("%d", &N);
		vector<pos> P(N);
		for (int i = 0; i < N; i++) 
			scanf("%d %d", &P[i].x, &P[i].y), P[i].idx = i;
		sort(P.begin(), P.end(), [](pos a, pos b) { return a.x == b.x ? a.y < b.y : a.x < b.x; });

		vector<pos> uph;
		int top = 0;
		for (int i = 0; i < N; i++)
		{
			while (top >= 2 && ccw(uph[top - 2], uph[top - 1], P[i]) > 0) uph.pop_back(), top--;
			uph.push_back(P[i]), top++;
		}
		bool chk[2000 + 5] = { false };
		for (pos p : uph)
		{
			printf("%d ", p.idx);
			chk[p.idx] = true;
		}
		for (int i = P.size() - 1; i >= 0; i--) 
			if(!chk[P[i].idx]) printf("%d ", P[i].idx);
		puts("");
	}
	return 0;
}