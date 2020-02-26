#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int height[80000 + 5];
stack<int> S;
int main()
{
	int N;
	long long ans = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &height[i]);

	S.push(height[1]);
	for (int i = 2; i <= N; i++)
	{
		while (!S.empty() && height[i] >= S.top())
		{
			S.pop();
		}
		ans += S.size();
		S.push(height[i]);
	}
	printf("%lld", ans);
	return 0;
}