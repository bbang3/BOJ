#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5 + 5;
int cnt[MN], rumor[MN], t[MN];
vector<int> G[MN];

int main()
{
	int N, M;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		while (1)
		{
			int dest;
			scanf("%d", &dest);
			if (dest == 0) break;
			G[i].push_back(dest);
			cnt[i]++;
		}
	}

	memset(t, -1, sizeof t);
	queue<int> Q;

	scanf("%d", &M);
	for (int i = 1; i <= M; i++)
	{
		int n;
		scanf("%d", &n);
		t[n] = 0;
		Q.push(n);
	}

	int curt = 0;
	while (!Q.empty())
	{
		curt++;
		int qsz = Q.size();
		for (int q = 1; q <= qsz; q++)
		{
			int cur = Q.front();
			Q.pop();
			//printf("%d ", cur);
			for (int next : G[cur])
			{
				rumor[next]++;
				if (t[next] == -1 && rumor[next] >= (cnt[next] + 1) / 2)
				{
					Q.push(next);
					t[next] = curt;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) printf("%d ", t[i]);

	return 0;
}