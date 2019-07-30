#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <float.h>
using namespace std;

struct pos
{
	double x, y;

	pos() {}
	pos(double x, double y) : x(x), y(y) {}

};

struct edge
{
	int v;
	double w;

	edge(int v, double w) : v(v), w(w) {}

	bool operator < (const edge e) const { return w < e.w; }
};

const int MN = 100 + 5;

pos S, E;
pos P[MN];
double G[MN][MN];
double dist[MN];
int N;
priority_queue<edge> PQ;

double getd(pos p1, pos p2)
{
	return sqrt(pow(fabs(p1.x - p2.x), 2) + pow(fabs(p1.y - p2.y), 2));
}

int main()
{
	scanf("%lf %lf", &S.x, &S.y);
	scanf("%lf %lf", &E.x, &E.y);
	scanf("%d", &N);
	
	P[1] = S, P[2] = E;
	for (int i = 3; i <= N + 2; i++)
		scanf("%lf %lf", &P[i].x, &P[i].y);
	N += 2;


	for (int i = 1; i <= N - 1; i++)
		for (int j = i + 1; j <= N; j++)
		{
			double dist = getd(P[i], P[j]);
			if(i == 1 && j == 2)
			{
				G[i][j] = G[j][i] = dist / 5;
			}
			else if (i == 1 || i == 2)
			{
				G[i][j] = dist / 5;
				G[j][i] = min(dist / 5, fabs(dist - 50) / 5 + 2);
			}
			else
			{
				G[i][j] = G[j][i] = min(dist / 5, fabs(dist - 50) / 5 + 2);
			}
		}

	fill(dist + 1, dist + N + 1, DBL_MAX);
	dist[1] = 0;
	PQ.push(edge(1, 0));
	while (!PQ.empty())
	{
		edge cur = PQ.top(); PQ.pop();

		if (cur.w != dist[cur.v]) continue;

		for (int next = 1; next <= N; next++)
		{
			if (dist[cur.v] + G[cur.v][next] < dist[next])
			{
				dist[next] = dist[cur.v] + G[cur.v][next];
				PQ.push(edge(next, dist[next]));
			}
		}
	}
	printf("%lf", dist[2]);

	return 0;
}