#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MN = 2000 + 5;

int N, X, Y;
char str[MN * 2];
int chk[MN];
int match[MN * 2];
int parent[MN];

void tree(int curidx, int cur, int prev)
{
	if (curidx > 2 * N) return;
	if (str[curidx] == '0')
	{
		if (prev != -1) parent[cur] = prev;
		match[curidx] = cur;
		tree(curidx + 1, cur + 1, cur);
	}
	else
	{
		match[curidx] = prev;
		tree(curidx + 1, cur, parent[prev]);
	}
}

void check(int n)
{
	chk[n]++;
	if (n == 1) return;
	check(parent[n]);
}

void print(int n)
{
	for (int i = 1; i <= 2 * N; i++)
		if (match[i] == n) printf("%d ", i);
}

int main()
{
	scanf("%d", &N);
	scanf("%s", str + 1);
	scanf("%d %d", &X, &Y);
	tree(1, 1, -1);
	if (match[X] == match[Y]) print(match[X]);
	else
	{
		check(match[X]);
		check(match[Y]);
		for (int i = N; i>0; i--)
			if (chk[i] == 2) { print(i); break; }
	}
	return 0;
}