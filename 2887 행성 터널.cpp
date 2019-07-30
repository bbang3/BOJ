#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

const int MN = 1e5 + 5;

struct planet
{
	int idx;
	int x;
	int y;
	int z;

	planet() {}
	planet(int idx, int x, int y, int z) : idx(idx), x(x), y(y), z(z) {}
};

struct edge
{
	int src;
	int dest;
	int w;

	edge() {}
	edge(int src, int dest, int w) : src(src), dest(dest), w(w) {}
};

int p[MN];
int N;
vector<edge> E;
planet P[MN];

int find(int n) // n의 부모 찾기
{
	if (n == p[n]) return n;
	return p[n] = find(p[n]);
}

bool merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return false;
	
	p[a] = b;

	return true;
}

int dist(planet a, planet b)
{
	int t = min(abs(a.x - b.x), abs(a.y - b.y));
	return min(t, abs(a.z - b.z));
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) p[i] = i;
	for (int i = 1; i <= N; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		P[i] = planet(i, a, b, c);
	}
	sort(P + 1, P + N + 1, [](planet a, planet b) { return a.x < b.x; });
	for (int i = 1; i <= N - 1; i++) E.push_back(edge(P[i].idx, P[i + 1].idx, dist(P[i], P[i + 1])));
	sort(P + 1, P + N + 1, [](planet a, planet b) { return a.y < b.y; });
	for (int i = 1; i <= N - 1; i++) E.push_back(edge(P[i].idx, P[i + 1].idx, dist(P[i], P[i + 1])));
	sort(P + 1, P + N + 1, [](planet a, planet b) { return a.z < b.z; });
	for (int i = 1; i <= N - 1; i++) E.push_back(edge(P[i].idx, P[i + 1].idx, dist(P[i], P[i + 1])));

	sort(E.begin(), E.end(), [](edge a, edge b) { return a.w < b.w; });
	long long ans = 0;
	int cnt = 0;

	for (int i = 0; i < E.size(); i++)
	{
		if (merge(E[i].src, E[i].dest))
		{
			cnt++;
			ans += E[i].w;
		}
		if (cnt == N - 1) break;
	}

	printf("%lld", ans);
	return 0;
}