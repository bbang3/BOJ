#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321
int V, E, K;
vector<pair<int, int> > graph[20001];
int dist[20001];

class CompareDist
{
public:
	bool operator()(pair<int, int> n1, pair<int, int> n2) {
		return n1.second > n2.second;
	}
};

int main()
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, CompareDist> PQ;
	scanf("%d%d%d", &V, &E, &K);
	for (int i = 1; i <= E; i++)
	{
		int src, dest, weight;
		scanf("%d %d %d", &src, &dest, &weight);
		graph[src].push_back({ dest,weight });
	}

	for (int i = 1; i <= V; i++) dist[i] = INF;
	dist[K] = 0;
	for (int i = 1; i <= V; i++) PQ.push({ i, dist[i] });
	while (!PQ.empty())
	{
		pair<int, int> cur = PQ.top(); PQ.pop();
		if (cur.second == dist[cur.first])
		{
			for (auto next : graph[cur.first])
			{
				if (dist[cur.first] + next.second < dist[next.first])
				{
					dist[next.first] = dist[cur.first] + next.second;
					PQ.push({ next.first, dist[next.first] });
				}
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF) puts("INF");
		else printf("%d\n", dist[i]);
	}
	return 0;
}