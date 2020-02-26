#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

priority_queue<int> maxH; // 최대 힙
priority_queue<int, vector<int>, greater<int> > minH; // 최소 힙
// 최대 힙에는 왼쪽 절반을, 최소 힙에는 오른쪽 절반을 넣는다.
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		int num;
		scanf("%d", &num);

		if (maxH.size() == minH.size()) maxH.push(num); 
		else minH.push(num); // 일단 넣어본다.

		// [최대 힙의 최댓값 < 최소 힙의 최솟값] 규칙을 만족하도록 조정한다.
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