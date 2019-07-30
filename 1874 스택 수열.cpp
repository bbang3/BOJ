#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int N;
int arr[100000 + 5];
char seq[300000 + 5];
int main()
{
	scanf("%d", &N);

	stack<int> S, T;
	for (int i = 1; i <= N; i++) scanf("%d", arr + i), S.push(arr[i]);

	int num = N, idx = 1;
	while (!S.empty())
	{
		while (!S.empty())
		{
			seq[idx++] = '-';
			T.push(S.top());
			S.pop();

			if (T.top() == num)
				break;
		}
		while (!T.empty() && T.top() == num)
		{
			seq[idx++] = '+';
			num--;
			T.pop();
		}
	}
	if (num != 0 || !S.empty() || !T.empty())
	{
		puts("NO");
		return 0;
	}
	for (int i = idx - 1; i >= 1; i--) printf("%c\n", seq[i]);

	return 0;
}