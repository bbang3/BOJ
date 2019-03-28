#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 100000 + 5;

int N, M;
bool time[MN];
int num[MN]; 

int main()
{
	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= N; i++)
	{
		num[i] = i;
		// ī�� ��ȣ�� ������������ �Ǿ� �ִٰ� ����
	}

	while (M--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		num[a]++, num[b]--; // �л�a���� ���� ����� �������Ƿ� num[a] + 1, �л� b���� ū ����� �������Ƿ� num[b] + 1
	}
	for (int i = 1; i <= N; i++)
	{
		if (time[num[i]]) // ī�� ��ȣ�� ��ħ -> ��� �߻�
		{
			puts("-1");
			return 0;
		}
		time[num[i]] = 1;
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", num[i]);
	return 0;
}