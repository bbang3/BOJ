#include <bits/stdc++.h>
using namespace std;

const int MN = 1e4 + 5;
bool isPrime[MN];
int dist[MN];

int main()
{
	for (int i = 2; i <= 9999; i++)
	{
		bool prime = true;
		for (int j = 2; j * j <= i; j++)
			if (i % j == 0)
			{
				prime = false;
				break;
			}
		if (prime) isPrime[i] = true;
	}

	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		memset(dist, -1, sizeof dist);
		queue<int> Q;
		dist[a] = 0;
		Q.push(a);

		while (!Q.empty())
		{
			int curnum = Q.front();
			Q.pop();
			for (int digit = 1; digit <= 1000; digit *= 10)
			{
				for (int n = 0; n <= 9; n++)
				{
					int tmp = curnum - curnum / digit % 10 * digit;
					int newnum = tmp + n * digit;
					if (newnum < 1000 || !isPrime[newnum] || dist[newnum] != -1) continue;
					dist[newnum] = dist[curnum] + 1;
					Q.push(newnum);
				}
			}
		}
		if (dist[b] == -1) puts("Impossible");
		else printf("%d\n", dist[b]);
	}

	return 0;
}