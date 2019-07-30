#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 1e4 + 5;

int p[MN], money[MN];
int N, M, k;
bool isfriend[MN];

int find(int n) { return p[n] == n ? n : p[n] = find(p[n]); }

void merge(int a, int b)
{
	a = find(a), b = find(b);

	if (a == b) return;
	
	if (money[a] > money[b]) p[a] = b;
	else p[b] = a;

	return;
}

int main()
{
	scanf("%d %d %d", &N, &M, &k);
	for (int i = 1; i <= N; i++) p[i] = i;
	for (int i = 1; i <= N; i++) scanf("%d", &money[i]);

	int a, b;
	while (M--)
	{
		scanf("%d %d", &a, &b);
		merge(a, b);
	}
	
	int sum = 0, par;
	for (int i = 1; i <= N; i++)
	{
		par = find(i);
		if(!isfriend[par])
			sum += money[par], isfriend[par] = true;
	}

	if (sum > k) puts("Oh no");
	else printf("%d", sum);
	return 0;
}