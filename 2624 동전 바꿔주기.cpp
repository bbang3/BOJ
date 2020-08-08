#include <bits/stdc++.h>
using namespace std;

const int MT = 1e4 + 5;
const int MK = 100 + 5;
int T, k;
int coin[MK][2]; // 0: 금액, 1: 개수
int D[MT][MK]; // D[i][j]: 1..j번 동전을 사용해 i원을 만들 수 있는 가짓수

int f(int m, int idx)
{
	int& ret = D[m][idx];
	if (ret != -1) return ret;
	if (idx == 0)
	{
		if (m == 0) return 1;
		else return 0;
	}
	if (m == 0) return 1;

	ret = 0;
	for (int i = 0; i <= coin[idx][1]; i++)
	{
		if (m - i * coin[idx][0] < 0) continue;
		ret += f(m - i * coin[idx][0], idx - 1);
	}
	return ret;
}

int main()
{
	scanf("%d %d", &T, &k);
	for (int i = 1; i <= k; i++)
		scanf("%d %d", &coin[i][0], &coin[i][1]);

	memset(D, -1, sizeof D);
	int ans = f(T, k);
	printf("%d", ans);
	return 0;
}