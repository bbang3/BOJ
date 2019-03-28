#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int N, M;
long long partsum[300000 + 5];
vector<pair<int, int> > A;
vector<pair<int, int> > B;
// first : index, second : num
int getapos(int idx)
{
	
	int left = 1, right = M, mid, ret = -1;
	while (left <= right)
	{
		mid = (left + right) / 2;

		if (B[mid].first >= idx)
		{
			right = mid - 1;
			ret = mid;
		}
		else left = mid + 1;
	}

	return ret;
}

int getbpos(int idx)
{

	int left = 1, right = M, mid, ret = -1;
	while (left <= right)
	{
		mid = (left + right) / 2;

		if (B[mid].first <= idx)
		{
			left = mid + 1;
			ret = mid;
		}
		else
		{
			right = mid - 1;
		}
	}

	return ret;
}

int main()
{
	scanf("%d", &N);
	A.resize(N + 5);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &A[i].first, &A[i].second);
	}
	scanf("%d", &M);
	B.resize(M + 5);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &B[i].first, &B[i].second);
	}
	sort(B.begin() + 1, B.begin() + M + 1);
	for (int i = 1; i <= M; i++)
		partsum[i] = partsum[i - 1] + B[i].second;
	int a, b;
	scanf("%d %d", &a, &b);
	long long ans = 0;
	for (int i = 1; i <= N; i++)
	{
		int curidx = A[i].first, curnum = A[i].second;

		int s = getapos(curidx + a), e = getbpos(curidx + b);

		if (s == -1 || e == -1) continue;
		ans += (partsum[e] - partsum[s - 1]) * (long long)curnum;
	}
	printf("%lld",ans);
	return 0;
}