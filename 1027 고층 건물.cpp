#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MN = 50 + 5;
ll height[MN]; // ���� ���� �����÷ο� ����

bool cansee(int s, int e) // s���� e�� �� �� �ִ���
{
	if (s > e) swap(s, e); // (s < e)�� ����

	// s < i < e�� ��� i�� ���� ((s, i) ���� < (i, e) ����) �����ؾ� �� (�Ʒ��� ����)
	for (int i = s + 1; i < e; i++)
	{
		if ((height[i] - height[s]) * (e - i) >=
			(height[e] - height[i]) * (i - s))
			return false;
	}
	return true;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &height[i]);

	int maxcnt = 0;
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = i - 1; j >= 1; j--)
			cnt += cansee(i, j);

		for (int j = i + 1; j <= N; j++)
			cnt += cansee(i, j);

		maxcnt = max(maxcnt, cnt);
	}
	printf("%d", maxcnt);

	return 0;
}