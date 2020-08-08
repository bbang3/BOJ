#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	priority_queue<int, vector<int>, greater<int>> PQ;
	int n;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &n);
		PQ.push(n);
	}
	for (int i = N + 1; i <= N * N; i++)
	{
		int k;
		scanf("%d", &k);
		PQ.push(k);
		PQ.pop();
	}
	printf("%d", PQ.top());
	return 0;
}