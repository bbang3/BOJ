#include <cstdio>
#include <algorithm>
using namespace std;

int money[50 + 5][2];
int D[100 + 5]; // D[i]: 기타줄 i개 사는 데 드는 최소 비용
// D[i] = min(D[i - 1...6] + money[j][0], D[i - 1] + money[j][1]) where 1<=j<=M
// D[0] = 0
// 그리디로 풀 수 있다고 함

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) scanf("%d %d", &money[i][0], &money[i][1]);

	D[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		D[i] = 2e9;
		for (int j = 1; j <= M; j++)
		{
			for (int k = 1; k <= 6; k++)
			{
				if (i < k) continue;
					D[i] = min(D[i], D[i - k] + money[j][0]);
			}
			D[i] = min(D[i], D[i - 1] + money[j][1]);
		}
	}
	printf("%d", D[N]);

	return 0;
}