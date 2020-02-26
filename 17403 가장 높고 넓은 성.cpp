#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

struct pos
{
	int x; int y; int idx;
	bool operator < (pos a)
	{
		return x == a.x ? y < a.y : x < a.x;
	}
};

const int MN = 1e3 + 5;
int N;
vector<pos> P;
int level[MN];

ll ccw(pos p1, pos p2, pos p3)
{
	ll ret = (ll)(p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	return 0;
}

vector<pos> getconvex(vector<pos> P)
{
	vector<pos> U, L;
	sort(P.begin(), P.end());

	for (int i = 0; i < P.size(); i++)
	{
		while (L.size() >= 2 && ccw(L[L.size() - 2], L[L.size() - 1], P[i]) <= 0)
			L.pop_back();
		L.push_back(P[i]);
	}

	if (!L.empty()) L.pop_back();
	for (int i = P.size() - 1; i >= 0; i--)
	{
		while (U.size() >= 2 && ccw(U[U.size() - 2], U[U.size() - 1], P[i]) <= 0)
			U.pop_back();
		U.push_back(P[i]);
	}
	if (U.size() >= 2)
	{
		for (int i = 0; i < U.size() - 1; i++)
			L.push_back(U[i]);

	}
	return L;
}

int main()
{
	scanf("%d", &N);
	P.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &P[i].x, &P[i].y), P[i].idx = i;

	int lv = 1;
	while (1)
	{
		auto cvx = getconvex(P);
		if (cvx.size() <= 2) break;
		for (pos p : cvx) level[p.idx] = lv;

		vector<pos> newP;
		for (int i = 0; i < P.size(); i++)
			if (level[P[i].idx] == 0) newP.push_back(P[i]);

		P = newP;
		lv++;
	}
	for (int i = 0; i < N; i++) printf("%d ", level[i]);

	return 0;
}