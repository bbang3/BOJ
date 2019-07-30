#include <cstdio>
#include <algorithm>
using namespace std;
int score[10001];
int D[10001][2];

int N;
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &score[i]);

	D[1][0] = D[1][1] = score[1];
	for (int i = 2; i <= N; i++)
	{
		D[i][0] = D[i - 1][1] + score[i];
		D[i][1] = max(D[i - 2][0], D[i - 2][1]) + score[i];
	}
	printf("%d", D[N][0] > D[N][1] ? D[N][0] : D[N][1]);
	return 0;
}