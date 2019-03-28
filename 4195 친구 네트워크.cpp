#include <cstdio>
#include <string>
#include <string.h>
#include <map>
#include <iostream>
using namespace std;
// 교훈 : string은 쓰지 말자.
const int MF = 200000 + 5;

int par[MF], num[MF];
int find(int n) // n의 부모 찾기
{
	if (n == par[n]) return n;
	return par[n] = find(par[n]);
}

void uni(int a, int b)
{
	int pa = find(a), pb = find(b);
	if (pa != pb)
	{
		par[pb] = pa;
		num[pa] += num[pb];
		num[pb] = 1;
	}
	printf("%d\n", num[pa]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int F;
		map<string, int> friends;
		scanf("%d", &F);

		for (int i = 1; i <= 2 * F + 1; i++) par[i] = i, num[i] = 1;

		int curidx = 0;
		for (int i = 0; i < F; i++)
		{
			char f1[30], f2[30];
			scanf("%s %s", f1, f2);
			if (friends.count(f1) == 0)
				friends[f1] = ++curidx;
			if (friends.count(f2) == 0)
				friends[f2] = ++curidx;

			uni(friends[f1], friends[f2]);
		}
	}
	return 0;
}