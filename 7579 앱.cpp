#include <bits/stdc++.h>
using namespace std;

const int MN = 100 + 5;
const int MC = 10000 + 5;
int m[MN], c[MN];
int N, M;
int D[MN][MC];
// D[i][j]: 1,...i��° �۸� ����ؼ� j���� ������� Ȯ�� ������ �ִ� �޸�
// *����: j�� �ִ��� 10000(100 * 100)��

int f(int idx, int cost)
{
	int& ret = D[idx][cost];
	if (ret != -1) return ret;
	if (idx == 0) return 0;

	ret = f(idx - 1, cost);
	if (cost - c[idx] >= 0) ret = max(ret, f(idx - 1, cost - c[idx]) + m[idx]);
	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) scanf("%d", m + i);
	for (int i = 1; i <= N; i++) scanf("%d", c + i);
	memset(D, -1, sizeof D);
	int ans = 0;
	for (int c = 0; c <= 100 * 100; c++)
		if (f(N, c) >= M)
		{
			printf("%d", c);
			return 0;
		}

	return 0;
}