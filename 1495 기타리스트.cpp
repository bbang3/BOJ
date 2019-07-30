#include <cstdio>
#include <algorithm>
using namespace std;
// D[i][j] : i번째 리스트를 이용해 볼륨 크기 j를 만들 수 있는지 여부

bool D[100 + 5][1000 + 5];
int V[100 + 5];
int N, S, M;
int main()
{
	scanf("%d %d %d", &N, &S, &M);
	for (int i = 1; i <= N; i++) scanf("%d", V + i);

	D[0][S] = true;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= M; j++)
			if (D[i - 1][j])
			{
				if(j + V[i] <= M) D[i][j + V[i]] = true;
				if(j - V[i] >= 0) D[i][j - V[i]] = true;
			}

	for (int j = M; j >= 0; j--)
		if (D[N][j])
		{
			printf("%d", j);
			return 0;
		}
	puts("-1");
	return 0;
}