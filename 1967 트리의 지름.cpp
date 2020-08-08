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
vector<int> len[MN + 5]; // len[i][j] : i�� ��忡�� j�� �������� ��� ����
vector<edge> graph[MN + 5];
int totallen = 0;

int f(int cur, int prev) // cur ��带 ��Ʈ�� �ϴ� Ʈ���� �ִ� ��� ���� ��ȯ
{

	int ret = 0;
	for (auto next : graph[cur])
	{
		if (next.v != prev)
		{
			int d = next.w + f(next.v, cur);
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
	f(1, -1);
	printf("%d", totallen);
	return 0;
}