#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

const int MN = 1000 + 5;
char s1[MN], s2[MN];
int D[MN][MN]; // ������ [1, i] / [1, j]�� �� �ּ� ���� ��
int main()
{
	scanf("%s %s", s1 + 1, s2 + 1);
	int i, j;
	for (i = 1; s1[i]; i++)
		for (j = 1; s2[j]; j++)
		{
			D[i][0] = i, D[0][j] = j;
			if (s1[i] == s2[j]) D[i][j] = D[i - 1][j - 1]; // ���ڰ� ���� -> ���� �ʿ� X (���� ������ �� �״��) 
			else D[i][j] = min({ D[i - 1][j] + 1, D[i][j - 1] + 1, D[i - 1][j - 1] + 1 }); 
			// 1) �� string ���� 2) �� string�� �߰� 3) �ش� �ڸ� ����
		}
	printf("%d", D[i - 1][j - 1]);
	return 0;
}