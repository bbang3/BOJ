#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MN = 50;
int N, totallen = 0;
int parent[MN + 5];
vector<int> cost[MN + 5];

void dfs(int cur, int target, int prev)
{
	bool ischild = true;
	for (int next : cost[cur]) {
		if (next != prev && next != target)
			dfs(next, target, cur), ischild = false;
	}
	if (ischild) totallen++;
}

int main()
{
	int root;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int dest;
		scanf("%d", &dest);
		if (dest == -1) root = i;
		parent[i] = dest;
		cost[i].push_back(dest);
		cost[dest].push_back(i);
	}
	int t;
	scanf("%d", &t);
	if (t != root)
		dfs(root, t, -1);
	printf("%d", totallen);

	return 0;
}