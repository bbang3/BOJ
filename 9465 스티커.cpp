#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int D[100000 + 5][3];
// D[i][0] : i��° ���� ��ƼĿ�� ���� ����, [1] : i��° ���� ���� ��ƼĿ ����, [2] : i��° ���� �Ʒ��� ��ƼĿ ����
int stick[100000 + 5][3];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) scanf("%d", &stick[i][1]);
		for (int i = 1; i <= N; i++) scanf("%d", &stick[i][2]);
		for (int i = 1; i <= N; i++)
		{
			D[i][0] = max(D[i - 1][0], max(D[i - 1][1], D[i - 1][2]));
			D[i][1] = max(D[i - 1][2], D[i - 1][0]) + stick[i][1];
			D[i][2] = max(D[i - 1][1], D[i - 1][0]) + stick[i][2];
		}
		printf("%d\n", max(D[N][0], max(D[N][1], D[N][2])));
	}
	return 0;
}