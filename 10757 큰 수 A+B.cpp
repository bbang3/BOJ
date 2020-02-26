#include <cstdio>
#include <algorithm>
#include <string.h>
#include <memory.h>
using namespace std;

const int MN = 10000 + 5;
char str1[MN], str2[MN];
int n1[MN], n2[MN];
int result[MN];

int main()
{
	scanf("%s %s", str1, str2);
	for (int i = 0; str1[i]; i++) n1[i] = str1[i] - '0';
	for (int i = 0; str2[i]; i++) n2[i] = str2[i] - '0';

	int idx1 = strlen(str1) - 1, idx2 = strlen(str2) - 1, i = 0; // ���� �ڸ� ���� ������� result[0]�� ����
	for (; idx1 >= 0 || idx2 >= 0; i++)
	{
		if (result[i] + n1[idx1] + n2[idx2] >= 10) // �޾ƿø�
			result[i + 1]++, result[i] += n1[idx1] + n2[idx2] - 10;
		else result[i] += n1[idx1] + n2[idx2];

		if (idx1 >= 0) idx1--;
		if (idx2 >= 0) idx2--;
	}
	for (int j = result[i] == 0 ? i - 1 : i; j >= 0; j--)
		printf("%d", result[j]);

	return 0;
}