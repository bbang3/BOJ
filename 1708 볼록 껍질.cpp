#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

struct pos
{
	int x; int y;
	bool operator < (pos a) { return y == a.y ? x < a.x : y > a.y; }
};

const int MN = 1e5 + 5;
typedef long long ll;
vector<pos> P;
int N;

int ccw(pos p1, pos p2, pos p3)
{
	ll res = (ll)p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= (ll)p2.x * p1.y + p3.x * p2.y + p1.x * p3.y;
	if (res > 0) return 1; // 반시계
	else if (res < 0) return -1;
	return 0;
}

pair<vector<pos>, vector<pos>> getConvex(vector<pos> P)
{
	sort(P.begin(), P.end());
	int top = 0;
	vector<pos> uph, lowh;
	for (int i = 0; i < P.size(); i++)
	{
		while (top >= 2 && ccw(uph[top - 2], uph[top - 1], P[i]) >= 0) top--, uph.pop_back();
		uph.push_back(P[i]), top++;
	}
	top = 0;
	for (int i = P.size() - 1; i >= 0; i--)
	{
		while (top >= 2 && ccw(lowh[top - 2], lowh[top - 1], P[i]) >= 0) top--, lowh.pop_back();
		lowh.push_back(P[i]), top++;
	}
	return { uph, lowh };
}

int main()
{
	scanf("%d", &N);
	P.resize(N);
	for (int i = 0; i < N; i++) scanf("%d %d", &P[i].x, &P[i].y);

	auto cvx = getConvex(P);
	int ans = cvx.first.size() + cvx.second.size() - 2; // 왼쪽 끝과 오른쪽 끝은 2번 포함되므로 -2
	printf("%d", ans); 

	return 0;
}