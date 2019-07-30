#include<cstdio>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
	int n, m, t;
	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		pq.push(t);
	}
	for (i = 0; i < m; i++) {
		int k = pq.top();
		pq.pop();
		int l = pq.top();
		pq.pop();
		pq.push(k + l);
		pq.push(k + l);
	}
	int sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	printf("%d", sum);
}