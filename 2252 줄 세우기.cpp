#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MN = 32000 + 5;
int N, M;
int ind[MN];
vector<int> G[MN];

int main()
{
	scanf("%d %d", &N, &M);

	int src, dest;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &src, &dest);
		G[src].push_back(dest);
		ind[dest]++;
	}

	queue<int> Q;
	for (int i = 1; i <= N; i++)
		if (ind[i] == 0) Q.push(i);

	int cnt = 0;
	while (!Q.empty())
	{
		int cur = Q.front(); Q.pop();
		printf("%d ", cur);
		for (int next : G[cur])
		{
			ind[next]--;
			if (ind[next] == 0)
				Q.push(next);
		}
	}

	return 0;
}