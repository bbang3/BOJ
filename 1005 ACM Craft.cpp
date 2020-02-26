#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

const int MN = 1000 + 5;
int T, N, S, W;
int time[MN];
int D[MN], ind[MN];
vector<int> G[MN];
queue<int> Q;

void bfs()
{
	for (int i = 1; i <= N; i++)
		if (ind[i] == 0) Q.push(i); // indegree�� 0��(������ ����X)�� ���� push
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for (int next : G[cur])
		{
			D[next] = max(D[next], time[next] + D[cur]); // ����� ���� update
			ind[next]--;
			if (ind[next] == 0) Q.push(next); // cur���� �� indegree 0�̸� push
		}
	}
}


int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &N, &S);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", time + i);
			D[i] = time[i];
			G[i].clear();
		}
		memset(ind, 0, sizeof(ind));
		int src, dest;
		for (int i = 0; i < S; i++)
		{
			scanf("%d %d", &src, &dest);
			G[src].push_back(dest);
			ind[dest]++; // indegree ���
		}
		scanf("%d", &W);
		bfs();
		printf("%d\n", D[W]);
	}
	return 0;
}