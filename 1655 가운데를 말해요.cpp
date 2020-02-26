#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

priority_queue<int> maxH; // �ִ� ��
priority_queue<int, vector<int>, greater<int> > minH; // �ּ� ��
// �ִ� ������ ���� ������, �ּ� ������ ������ ������ �ִ´�.
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		int num;
		scanf("%d", &num);

		if (maxH.size() == minH.size()) maxH.push(num); 
		else minH.push(num); // �ϴ� �־��.

		// [�ִ� ���� �ִ� < �ּ� ���� �ּڰ�] ��Ģ�� �����ϵ��� �����Ѵ�.
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