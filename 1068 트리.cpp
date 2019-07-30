#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MN = 50;
int N, totallen = 0;
int parent[MN + 5];
vector<int> dist[MN + 5];

void dfs(int cur, int target, int prev)
{
	bool ischild = true;
	for (int next : dist[cur]) {
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
		dist[i].push_back(dest);
		dist[dest].push_back(i);
	}
	int t;
	scanf("%d", &t);
	if (t != root)
		dfs(root, t, -1);
	printf("%d", totallen);

	return 0;
}