#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int K;
vector<int> G[15], RG[15];
int ind[15], ind2[15], num[15]; // num[i] : i번 정점에 할당된 숫자
priority_queue<int> PQ;

int main()
{
	scanf("%d", &K);
	char c;
	for (int i = 2; i <= K + 1; i++)
	{
		getchar();
		scanf("%1c", &c);
		if (c == '<')
		{
			G[i - 1].push_back(i);
			ind[i]++;
			ind2[i]++;
		}
		else
		{
			G[i].push_back(i - 1);
			ind[i - 1]++;
			ind2[i - 1]++;
		}
	}

	for (int i = 1; i <= K + 1; i++)
		if (ind[i] == 0)
			PQ.push(i);
		
	int n = 9 - K;
	while (!PQ.empty())
	{
		int cur = PQ.top(); PQ.pop();
		num[cur] = n++;
		for (auto next : G[cur])
		{
			ind[next]--;
			if (ind[next] == 0)
				PQ.push(next);
		}
	}
	for (int i = 1; i <= K + 1; i++) printf("%d", num[i]);
	puts("");

	for (int i = 1; i <= K + 1; i++)
		if (ind2[i] == 0)
			PQ.push(-i);

	n = 0;
	while (!PQ.empty())
	{
		int cur = -PQ.top(); PQ.pop();
		num[cur] = n++;
		for (auto next : G[cur])
		{
			ind2[next]--;
			if (ind2[next] == 0)
				PQ.push(-next);
		}
	}
	for (int i = 1; i <= K + 1; i++) printf("%d", num[i]);

	return 0;
}