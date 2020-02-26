#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

const int MN = 500 + 5;
int N;
int time[MN];
int D[MN], ind[MN];
vector<int> G[MN];
queue<int> Q;

int main()
{
	//freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	int pre;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", time + i);
		D[i] = time[i];
		while (1)
		{
			scanf("%d", &pre);
			if (pre == -1) break;
			ind[i]++;
			G[pre].push_back(i);
		}
	}
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
	for (int i = 1; i <= N; i++) printf("%d\n", D[i]);
	return 0;
}