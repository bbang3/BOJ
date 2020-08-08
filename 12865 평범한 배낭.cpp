#include <bits/stdc++.h>
using namespace std;

struct item { int w; int v; };
const int MN = 100 + 5;
const int MK = 1e5 + 5;

item items[MN];
int D[MN][MK];
// D[i][j]: 1...i��° ������ Ȱ��, ���� �� j�� ���� �� �ִ� �ִ� ��ġ
// D[i][j] = max(D[i - 1][j - v], D[i - 1][j])

int f(int i, int weight)
{
	int& ret = D[i][weight];
	if (ret != -1) return ret;
	if (i == 0) return 0;

	ret = f(i - 1, weight); // i��° ���� ������� ����
	if (weight >= items[i].w)
		ret = max(ret, f(i - 1, weight - items[i].w) + items[i].v); // i��° ���� ���

	return ret;
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%d %d", &items[i].w, &items[i].v);
	memset(D, -1, sizeof D);

	int ans = 0;
	for (int w = 0; w <= K; w++)
		ans = max(ans, f(N, w));

	printf("%d", ans);

	return 0;
}