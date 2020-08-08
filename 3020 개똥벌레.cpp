#include <cstdio>
#include <algorithm>
using namespace std;


const int MH = 5e5 + 5;
int height[2][MH]; // [0][i]: 높이가 i 이상인 석순 개수, [1]: 종유석

int main()
{
	int N, H;
	scanf("%d %d", &N, &H);
	int h;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &h);
		if (i % 2 == 1) height[0][h]++;
		else height[1][h]++;
	}
	for (int i = H; i >= 1; i--)
	{
		height[0][i] += height[0][i + 1];
		height[1][i] += height[1][i + 1];
	}

	int mini = 2e9, mincnt = 1;
	for (int i = 1; i <= H; i++)
	{
		int curi = height[0][i] + height[1][H - i + 1];
		if (curi < mini)
		{
			mini = curi;
			mincnt = 1;
		}
		else if (curi == mini) mincnt++;
	}
	printf("%d %d", mini, mincnt);

	return 0;
}