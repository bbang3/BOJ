#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, C;
int w[35];

vector<int> wl1;
vector<int> wl2;
void f(int curidx, int curc, int N, vector<int>& V)
{
	if (curc > C) return;
	if (curidx > N) {
		V.push_back(curc);
		return;
	}
	f(curidx + 1, curc, N, V);
	f(curidx + 1, curc + w[curidx], N, V);
}

int solve()
{
	int ans = 0;
	int border = wl2.size() - 1;
	for (int i = 0; i<wl1.size(); i++)
	{
		for (int j = border; j >= 0; j--)
		{
			if (wl1[i] + wl2[j] > C) border--;
			else
			{
				ans += (j + 1);
				break;
			}
		}
	}
	return ans;
}

int main()
{
	scanf("%d %d", &N, &C);
	for (int i = 1; i <= N; i++) scanf("%d", w + i);

	f(1, 0, N / 2, wl1);
	f(N / 2 + 1, 0, N, wl2);
	sort(wl1.begin(), wl1.end());
	sort(wl2.begin(), wl2.end());

	printf("%d", solve());
	return 0;
}