#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

priority_queue<int> maxH; // 중앙값보다 작은 값들을 max Heap에 넣음
priority_queue<int, vector<int>, greater<int> > minH; // 중앙값보다 큰 값들을 min Heap에 넣음
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		int num;
		scanf("%d", &num);

		if (maxH.size() == minH.size()) maxH.push(num);
		else minH.push(num);

		if (!maxH.empty() && !minH.empty() && maxH.top() > minH.top())
		{
			int a = maxH.top(), b = minH.top();
			maxH.pop(); minH.pop();
			maxH.push(b); minH.push(a);
		}
		printf("%d\n", maxH.top());
	}

	return 0;
}