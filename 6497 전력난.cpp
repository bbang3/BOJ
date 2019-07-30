#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 200000 + 5;
const int MM = 200000 + 5;
int N, M;
int p[MN];

struct edge
{
	int src, dest, w;

	edge() {}
	edge(int src, int dest, int w) : src(src), dest(dest), w(w) {}

	bool operator < (const edge a) const { return w < a.w; }
};

edge E[MM];

int find(int n) { return p[n] == n ? n : p[n] = find(p[n]); }

bool merge(int a, int b)
{
	a = find(a), b = find(b);

	if (a == b) return false;
	if (a > b) p[a] = b;
	else p[b] = a;

	return true;
}

int main()
{
	while (1)
	{
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0) return 0;
		for (int i = 1; i <= N; i++) p[i] = i;

		int edgesum = 0;
		int src, dest, w;
		for (int i = 1; i <= M; i++)
		{
			scanf("%d %d %d", &src, &dest, &w);
			E[i] = edge(src, dest, w);
			edgesum += w;
		}

		sort(E + 1, E + M + 1);

		int sum = 0, cnt = 0;
		for (int i = 1; i <= M; i++)
		{
			if (merge(E[i].src, E[i].dest))
			{
				cnt++;
				sum += E[i].w;
			}
			if (cnt == N - 1) break;
		}
		printf("%d\n", edgesum - sum);
	}

	return 0;
}