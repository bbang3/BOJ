#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
// BFS 응용
const int END = 123456780;
map<int, int> M;

int nextstat(int stat, int si, int sj, int ei, int ej) // 빈 칸을 (si, sj)에서 (ei, ej)로 이동했을 때의 상태
{
	int sdig = pow(10, 8 - 3 * si - sj), sv = stat / sdig % 10;
	int edig = pow(10, 8 - 3 * ei - ej), ev = stat / edig % 10;

	int ret = stat;
	ret -= sv * sdig + ev * edig;
	ret += sv * edig + ev * sdig;
	return ret;
}

int main()
{
	int status = 0, n;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &n);
		status = status * 10 + n;
	}

	int d[2][4] = { { -1,0,1,0 },{ 0,-1,0,1 } };
	queue<int> Q;
	Q.push(status);
	M.insert({ status, 0 });

	while (!Q.empty())
	{
		int curs = Q.front();
		Q.pop();
		if (curs == END) break;

		int tmp = curs, idx = 8;
		while (tmp % 10 != 0)
		{
			tmp /= 10;
			idx--;
		}
		int ci = idx / 3, cj = idx % 3;

		for (int k = 0; k < 4; k++)
		{
			int ni = ci + d[0][k], nj = cj + d[1][k];
			if (!(ni >= 0 && ni <= 2 && nj >= 0 && nj <= 2)) continue;
			int ns = nextstat(curs, ci, cj, ni, nj);
			if (!M.count(ns))
			{
				Q.push(ns);
				M.insert({ ns, M[curs] + 1 });
			}
		}
	}
	printf("%d", M.count(END) ? M[END] : -1);

	return 0;
}