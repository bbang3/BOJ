#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

const int MV = 1e5 + 5;

struct planet
{
	int x;
	int y;
	int z;

	planet() {}
	planet(int x, int y, int z) : x(x), y(y), z(z) {}
};

struct edge
{
	int src;
	int dest;
	int w;

	edge() {}
	edge(int src, int dest, int w) : src(src), dest(dest), w(w) {}
};

int par[MV];
int V;
vector<edge> edges;
planet P[MV];

int find(int n) // n의 부모 찾기
{
	if (n == par[n]) return n;
	return par[n] = find(par[n]);
}

bool uni(int a, int b)
{
	int pa = find(a), pb = find(b);
	if (pa == pb) return false;
	par[pa] = pb;
	return true;
}

int dist(planet a, planet b)
{
	int t = min(abs(a.x - b.x), abs(a.y - b.y));
	return min(t, abs(a.z - b.z));
}

int main()
{
	scanf("%d", &V);
	for (int i = 1; i <= V; i++) par[i] = i;
	for (int i = 0; i < V; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		P[i] = planet(a, b, c);
	}

	sort(P, P + V, [](planet a, planet b) {
		if (a.x != b.x) return a.x < b.x;
		if (a.y != b.y) return a.y < b.y;
		if (a.z != b.z) return a.z < b.z;
	});

	long long ans = 0;

	for (int i = 0; i < V - 2; i++)
	{
		ans += dist(P[i], P[i + 1]);
	}

	printf("%lld", ans);
	return 0;
}