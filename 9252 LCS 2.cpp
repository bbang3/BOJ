#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 1000 + 5;
char s1[MN], s2[MN];
int D[MN][MN];
// D[i][j] : 1��° ������ i��°����, 2��° ������ j��° ���ұ��� ���� �� LCS ����

void track(int i, int j) // [1, i] [1, j] LCS ����
{
	if (i < 1 || j < 1) return;
	// DP���� ū ������ �������Ѵ�.
	if (s1[i] == s2[j]) // �� ��쿡�� LCS�� ���Ե� ���ڰ� �߰��Ǵ� ����̹Ƿ� printf
		track(i - 1, j - 1), printf("%c", s1[i]);
	else if (D[i - 1][j] > D[i][j - 1]) 
		track(i - 1, j);
	else track(i, j - 1);
}

int main()
{
	scanf("%s %s", s1 + 1, s2 + 1);
	int ans = 0, i , j;
	for (i = 1; s1[i]; i++)
		for (j = 1; s2[j]; j++)
		{
			if (s1[i] == s2[j]) D[i][j] = D[i - 1][j - 1] + 1;
			else D[i][j] = max(D[i - 1][j], D[i][j - 1]);
		}

	printf("%d\n", D[i - 1][j - 1]);
	track(i - 1, j - 1);
	return 0;
}