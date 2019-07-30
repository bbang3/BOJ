#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 1000 + 5;
char s1[MN], s2[MN];
int D[MN][MN];
// D[i][j] : 1번째 수열은 i번째까지, 2번째 수열은 j번째 원소까지 썼을 때 LCS 길이

int main()
{
	scanf("%s %s", s1 + 1, s2 + 1);
	int ans = -1;
	for (int i = 1; s1[i]; i++)
		for (int j = 1; s2[j]; j++)
		{
			if (s1[i] == s2[j]) D[i][j] = D[i - 1][j - 1] + 1;
			else D[i][j] = max(D[i - 1][j], D[i][j - 1]);
			ans = max(ans, D[i][j]);
		}

	printf("%d", ans);
	return 0;
}