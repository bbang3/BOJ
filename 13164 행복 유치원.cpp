#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
int arr[300000 + 5];
vector<long long> V;
int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%d", arr + i);

	long long ans = arr[N] - arr[1];

	for (int i = 2; i <= N; i++)
		V.push_back(-(arr[i] - arr[i - 1]));
	sort(V.begin(), V.end());
	
	for (int i = 0; i < K - 1; i++)
		ans -= -V[i];
	printf("%lld", ans);

	return 0;
}