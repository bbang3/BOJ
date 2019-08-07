#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

const int MN = 20000 + 5;
const int MM = 300000 + 5;

struct edge // ���� ����ü
{
	int v; // ����
	int w; // ����ġ

	edge(int v, int w) : v(v), w(w) {} // ���� ����ü �ʱ�ȭ�ϱ�
	
	bool operator < (const edge a) const 
	{
		return w > a.w; // PQ���� ����ġ�� ���� ������ ������ �ϱ� ���� ������ �����ε�(�ε�ȣ ���� �ݴ��� �Ϳ� ����)
	}
};

int N, M, S;
vector<edge> G[MN];
priority_queue<edge> PQ; // edge������ PQ ����
int cost[MN];

int main()
{
	scanf("%d%d%d", &N, &M, &S);
	for (int i = 1; i <= M; i++)
	{
		int src, dest, weight;
		scanf("%d %d %d", &src, &dest, &weight);
		G[src].push_back(edge(dest, weight));
	}

	for (int i = 1; i <= N; i++) cost[i] = INF; // ó���� ��� ������ dist���� �ſ� ū ������ �ʱ�ȭ
	cost[S] = 0; // ���� ������ dist�� = 0���� �ʱ�ȭ
	PQ.push(edge(S, cost[S])); // ���� ���� �ְ� ����
	while (!PQ.empty())
	{
		edge cur = PQ.top(); PQ.pop();

		if (cost[cur.v] != cur.w) continue;

		for (edge next : G[cur.v]) 
		{ 
			if (cost[cur.v] + next.w < cost[next.v])
			{
				cost[next.v] = cost[cur.v] + next.w;
				PQ.push(edge(next.v, cost[next.v]));
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (cost[i] == INF) puts("INF"); // INF�̸� ������ �� ���� �ȵ� �� �� �������� �� �� ����
		else printf("%d\n", cost[i]);
	}
	return 0;
}