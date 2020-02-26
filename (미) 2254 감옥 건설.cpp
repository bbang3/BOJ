#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

struct pos
{
	int x; int y; int idx;
	bool operator < (pos a) { return x == a.x ? y < a.y : x < a.x; }
};

const int MN = 1e3 + 5;
typedef long long ll;
vector<pos> P;
int N;
pos jail;
bool chk[MN];

int ccw(pos p1, pos p2, pos p3)
{
	ll res = (ll)p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= (ll)p2.x * p1.y + p3.x * p2.y + p1.x * p3.y;
	if (res > 0) return 1; // ¹Ý½Ã°è
	else if (res < 0) return -1;
	return 0;
}

pair<vector<pos>,vector<pos>> getConvex(vector<pos> P)
{
	sort(P.begin(), P.end());
	int top = 0;
	vector<pos> uph, lowh;
	for (int i = 0; i < P.size(); i++)
	{
		if (chk[P[i].idx]) continue;
		while (top >= 2 && ccw(uph[top - 2], uph[top - 1], P[i]) >= 0) top--, uph.pop_back();
		uph.push_back(P[i]), top++;
	}
	top = 0;
	for (int i = P.size() - 1; i >= 0; i--)
	{
		if (chk[P[i].idx]) continue;
		while (top >= 2 && ccw(lowh[top - 2], lowh[top - 1], P[i]) >= 0) top--, lowh.pop_back();
		lowh.push_back(P[i]), top++;
	}

	return {uph, lowh};
}

bool isIn(pair<vector<pos>,vector<pos>> cvx)
{
	if (cvx.first.size() <= 1 || cvx.second.size() <= 1) return false;

	bool C[2] = { false };
	for (int i = 1; i < cvx.first.size(); i++)
	{
		if (ccw(cvx.first[i - 1], cvx.first[i], jail) >= 0) C[1] = true;
		else C[0] = false;
	}
	for (int i = 1; i < cvx.second.size(); i++)
	{
		if (ccw(cvx.second[i - 1], cvx.second[i], jail) >= 0) C[1] = true;
		else C[0] = false;
	}
	if (C[0] && C[1]) return false;
	return true;
}

int main()
{
	scanf("%d", &N);
	P.resize(N);
	scanf("%d %d", &jail.x, &jail.y);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &P[i].x, &P[i].y), P[i].idx = i;

	int ans = 0;
	while (1)
	{
		auto cvx = getConvex(P);
		if (!isIn(cvx)) break;
		for (pos p : cvx.first) chk[p.idx] = true;
		for (pos p : cvx.second) chk[p.idx] = true;
		vector<pos> newP;
		for (int i = 0; i < P.size(); i++)
			if (!chk[P[i].idx]) newP.push_back(P[i]), printf("%d ", P[i].idx);
		P = newP;
		ans++;
	}
	printf("%d", ans);

	return 0;
}