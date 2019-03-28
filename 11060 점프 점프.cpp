#include <cstdio>
#include <memory.h>
int N;
int jump[1005];
int D[1005];
// d[i] : i번째 칸까지 가는 데 필요한 최소 점프 횟수
// d[i] = d[j] + 1 : (i-j) <= A[j]

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", jump + i);
	memset(D, -1, sizeof(D));

	D[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			if (jump[j] < i - j || jump[j] == 0 || D[j] == -1) continue;
			if (D[i] == -1 || D[i] > D[j] + 1) D[i] = D[j] + 1;
		}
	}
	printf("%d", D[N]);
	return 0;
}