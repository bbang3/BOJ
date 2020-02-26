#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int MN = 1e5 + 5;
int N, K;
bool visit[MN];

int main()
{
	scanf("%d %d", &N, &K);
	if (N > K)
	{
		printf("%d", N - K);
		return 0;
	}
	queue<int> Q;
	int ans = 0;

	visit[N] = true;
	Q.push(N);
	while (!Q.empty())
	{
		int qsz = Q.size();
		bool flag = false;
		while (qsz--)
		{
			int cur = Q.front();
			Q.pop();
			if (cur == K)
			{
				flag = true;
				break;
			}
			if (cur + 1 <= 100000 && !visit[cur + 1])
				Q.push(cur + 1), visit[cur + 1] = true;
			if (cur - 1 >= 0 && !visit[cur - 1])
				Q.push(cur - 1), visit[cur - 1] = true;
			if (cur * 2 <= 100000 && !visit[cur * 2])
				Q.push(cur * 2), visit[cur * 2] = true;
		}
		if (flag) break;
		ans++;
	}
	printf("%d", ans);

	return 0;
}