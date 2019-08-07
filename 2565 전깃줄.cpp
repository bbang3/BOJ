#include <cstdio>
#include <algorithm>
using namespace std;

struct line { int s; int e; };
bool cmp(line a, line b) { return a.s < b.s; }

line L[100 + 5];
int D[100 + 5]; // D[i] : [1, i] 구간 LIS 길이
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d %d", &L[i].s, &L[i].e);
	sort(L + 1, L + N + 1, cmp);

	int cnt = 1;
	for (int i = 1; i <= N; i++)
	{
		D[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (L[j].e < L[i].e)
				D[i] = max(D[i], D[j] + 1);
		}
		cnt = max(cnt, D[i]);
	}
	printf("%d", N - cnt);


	return 0;
}