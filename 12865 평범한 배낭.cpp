#include <cstdio>
#include <algorithm>
using namespace std;

struct item { int w; int v; };
item I[100 + 5];
int D[100000 + 5]; // D[i] : i ������ ���Է� ���� �� �ִ� �ִ� ��ġ
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%d %d", &I[i].w, &I[i].v);

	int ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = K; j >= I[i].w; j--) // ū �ʺ��� �����ؾ� ��. ���� �ʺ��� �ϸ� i��° ������ ���� �� ���� ��.
		{
			D[j] = max(D[j], D[j - I[i].w] + I[i].v);
			ans = max(ans, D[j]);
		}

	printf("%d", ans);

	return 0;
}