#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MN = 1e4 + 5;
vector<int> G[MN];
int P[MN], D[MN][2];
// D[i][0] : i번째 마을을 포함하지 않음 1: 포함함
// D[i][0] = i의 자식인 모든 j에 대해 sum(max(D[j][1],  D[j][0]))
// D[i][1] = sum(D[j][0] + P[i])
int dfs(int i, int sel, int prev)
{
	if (D[i][sel]) return D[i][sel];

	int &ret = D[i][sel];
	if (sel) ret += P[i];
	for (int next : G[i])
	{
		if (next != prev)
		{
			if (sel) ret += dfs(next, 0, i);
			else ret += max(dfs(next, 0, i), dfs(next, 1, i));
		}
	}
	return ret;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", P + i);
	for (int i = 1; i <= N - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].push_back(b); G[b].push_back(a);
	}

	printf("%d", max(dfs(1, 0, -1), dfs(1, 1, -1)));
	return 0;
}