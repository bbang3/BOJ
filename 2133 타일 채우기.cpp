#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int D[35]; // D[i] : 3*iũ���� ���� ä��� ����� ��

int main()
{
	scanf("%d", &N);
	
	// *** i�� Ȧ���̸� ���� �� ����.
	D[2] = 3, D[4] = 11;
	for (int i = 6; i <= N; i += 2)
	{
		D[i] += D[i - 2] * 3;
		for (int j = i; j >= 4; j -= 2) // i - 4, i - 6, i - 8, ... �� ���� ���� ��� 2���� ����
		{
			D[i] += D[i - j] * 2;
		}

	}
	printf("%d", D[N]);
	return 0;
}