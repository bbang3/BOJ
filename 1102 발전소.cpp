#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 987654321
int N, P, status;
int C[16 + 5][16 + 5];
int D[(1 << 20) + 5]; // D[stat] : ���� ������ on ���°� stat�� �� ���� �����Ҹ� �Ѵ� �� ��� �ּ� ���

int f(int curstat, int cnt)
{
	if (cnt >= P)
	{
		return 0;
	}
	int& ret = D[curstat];
	if (ret != INF) return ret;

	for (int i = 0; i < N; i++)
	{
		if (!(curstat & (1 << i))) continue;
		for (int j = 0; j < N; j++)
		{
			if (curstat & (1 << j) ) continue;
			ret = min(ret, f(curstat | (1 << j), cnt + 1) + C[i][j]);
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &C[i][j]);
	getchar();
	char c; int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%1c", &c);
		if (c == 'Y') status |= (1 << i), cnt++;
	}
	scanf("%d", &P);
	for (int i = 0; i < (1 << 20); i++) D[i] = INF;

	int ans = f(status, cnt);
	printf("%d", ans == INF ? -1 : ans);



	return 0;
}