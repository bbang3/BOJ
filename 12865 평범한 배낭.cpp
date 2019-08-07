#include <cstdio>
#include <algorithm>
using namespace std;

struct item { int w; int v; };
item I[100 + 5];
int D[100000 + 5]; // D[i] : i 이하의 무게로 얻을 수 있는 최대 가치
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%d %d", &I[i].w, &I[i].v);

	int ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = K; j >= I[i].w; j--) // 큰 쪽부터 갱신해야 함. 작은 쪽부터 하면 i번째 물건을 여러 번 쓰게 됨.
		{
			D[j] = max(D[j], D[j - I[i].w] + I[i].v);
			ans = max(ans, D[j]);
		}

	printf("%d", ans);

	return 0;
}