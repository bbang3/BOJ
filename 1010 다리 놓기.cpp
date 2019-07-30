#include <cstdio>
using namespace std;

int D[30][30];

int ncr(int n, int r)
{
	if (r > n) return 0;
	if (D[n][r])
		return D[n][r];
	if (r == 1) return D[n][r] = n;
	if (r == 0) return D[n][r] = 1;
	
	return D[n][r] = ncr(n - 1, r - 1) + ncr(n - 1, r);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%d\n", ncr(m, n));
	}
	return 0;
}