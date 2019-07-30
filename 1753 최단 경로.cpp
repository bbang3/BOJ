#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

const int MN = 20000 + 5;
const int MM = 300000 + 5;

struct edge // 간선 구조체
{
	int v; // 정점
	int w; // 가중치

	edge(int v, int w) : v(v), w(w) {} // 쉽게 구조체 초기화하기
	
	bool operator < (const edge a) const 
	{
		return w > a.w; // PQ에서 가중치가 작은 순으로 뽑히게 하기 위한 연산자 오버로딩(부등호 방향 반대인 것에 유의)
	}
};

int N, M, S;
vector<edge> G[MN];
priority_queue<edge> PQ; // edge형으로 PQ 선언
int dist[MN];

int main()
{
	scanf("%d%d%d", &N, &M, &S);
	for (int i = 1; i <= M; i++)
	{
		int src, dest, weight;
		scanf("%d %d %d", &src, &dest, &weight);
		G[src].push_back(edge(dest, weight));
	}

	for (int i = 1; i <= N; i++) dist[i] = INF; // 처음엔 모든 정점의 dist값을 매우 큰 값으로 초기화
	dist[S] = 0; // 시작 정점의 dist값 = 0으로 초기화
	PQ.push(edge(S, dist[S])); // 시작 정점 넣고 시작
	while (!PQ.empty())
	{
		edge cur = PQ.top(); PQ.pop();

		if (dist[cur.v] != cur.w) continue;

		for (edge next : G[cur.v]) 
		{ 
			if (dist[cur.v] + next.w < dist[next.v])
			{
				dist[next.v] = dist[cur.v] + next.w;
				PQ.push(edge(next.v, dist[next.v]));
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == INF) puts("INF"); // INF이면 갱신이 한 번도 안됨 → 그 정점까지 갈 수 없음
		else printf("%d\n", dist[i]);
	}
	return 0;
}