#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MN = 50 + 5;
ll height[MN]; // 기울기 계산시 오버플로우 조심

bool cansee(int s, int e) // s에서 e를 볼 수 있는지
{
	if (s > e) swap(s, e); // (s < e)를 유지

	// s < i < e인 모든 i에 대해 ((s, i) 기울기 < (i, e) 기울기) 만족해야 함 (아래로 볼록)
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