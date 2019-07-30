#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
	int v;
	int w;
	edge(int dest, int w) : v(dest), w(w) {}
};

const int MN = 10000;
int N;
vector<int> len[MN + 5]; // len[i] : i번 노드에서 갈 수 있는 최대 길이
vector<edge> dist[MN + 5];
int totallen = 0;

int numbering(int cur, int prev) // cur 노드에서 갈 수 있는 최대 길이 구함.
{

	int ret = 0;
	for (auto next : dist[cur])
	{
		if (next.v != prev)
		{
			int d = next.w + numbering(next.v, cur);
			ret = max(d, ret); // 자신의 서브트리로 내려가는 경로 중 가장 긴 길이 구함
			len[cur].push_back(d);
		}
	}
	if (len[cur].size() > 0) // 리프 노드가 아닐 경우
	{
		sort(len[cur].begin(), len[cur].end());
		reverse(len[cur].begin(), len[cur].end());
		if (len[cur].size() >= 2) totallen = max(totallen, len[cur][0] + len[cur][1]); // 자식이 2개 이상일 경우 자식->자신->자식이 최대일 수도 있음.
		totallen = max(totallen, len[cur][0]);  // 트리가 한쪽으로 치우쳐 있을 경우
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		dist[a].push_back(edge(b, w));
		dist[b].push_back(edge(a, w));
	}
	numbering(1, -1);
	printf("%d", totallen);
	return 0;
}