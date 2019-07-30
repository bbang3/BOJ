#include <cstdio>
#include <algorithm>
using namespace std;

const int MX = 1000 + 5;

int p[MX];
int N;

int find(int n) { return p[n] == n ? n : p[n] = find(p[n]); }

void merge(int a, int b)
{
	a = find(a), b = find(b);

	if (a == b) return;
	if (a < b) p[a] = b;
	else p[b] = a;

	return;
}

int main()
{
	for (int i = 1; i <= N; i++) p[i] = i;
	return 0;
}