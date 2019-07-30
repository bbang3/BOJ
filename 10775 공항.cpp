#include <cstdio>
#include <algorithm>
using namespace std;

const int MX = 1e5 + 5;
int G, P;
int g[MX], p[MX], use[MX];

int find(int n) { return p[n] == n ? n : p[n] = find(p[n]); }

void merge(int a, int b)
{
	a = find(a), b = find(b);

	if (a == b) return;
	p[a] = b;

	return;
}

int main()
{
	scanf("%d %d", &G, &P);
	for (int i = 1; i <= G; i++) p[i] = i;

	int cnt = 0;
	for (int i = 1; i <= P; i++)
	{
		scanf("%d", &g[i]);
		if (!use[g[i]])
		{
			use[g[i]] = 1;
			if(g[i] != 1)
				merge(g[i], g[i] - 1);
		}
		else
		{
			int par = find(g[i]);
			if (!use[par])
			{
				use[par] = 1;
				if(par != 1) 
					merge(par, par - 1);
			}
			else break;
		}
		//for (int i = 1; i <= G; i++) printf("%d ", p[i]); puts("");
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}