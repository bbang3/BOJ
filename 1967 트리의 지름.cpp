#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
	int dest;
	int w;
	edge(int dest, int w) : dest(dest), w(w) {}
};

const int MN = 10000;
int N;
vector<int> len[MN + 5]; // len[i] : i�� ��忡�� �� �� �ִ� �ִ� ����
vector<edge> graph[MN + 5];
int totallen = 0;

int dfs(int cur, int prev) // cur ��忡�� �� �� �ִ� �ִ� ���� ����.
{

	int ret = 0;
	for (auto next : graph[cur])
	{
		if (next.dest != prev)
		{
			int d = next.w + dfs(next.dest, cur);
			ret = max(d, ret); // �ڽ��� ����Ʈ���� �������� ��� �� ���� �� ���� ����
			len[cur].push_back(d);
		}
	}
	if (len[cur].size() > 0) // ���� ��尡 �ƴ� ���
	{
		sort(len[cur].begin(), len[cur].end());
		reverse(len[cur].begin(), len[cur].end());
		if (len[cur].size() >= 2) totallen = max(totallen, len[cur][0] + len[cur][1]); // �ڽ��� 2�� �̻��� ��� �ڽ�->�ڽ�->�ڽ��� �ִ��� ���� ����.
		totallen = max(totallen, len[cur][0]);  // Ʈ���� �������� ġ���� ���� ���
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
		graph[a].push_back(edge(b, w));
		graph[b].push_back(edge(a, w));
	}
	dfs(1, -1);
	printf("%d", totallen);
	return 0;
}