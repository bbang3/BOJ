#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int priority(char ch)
{
	if (ch == '*' || ch == '/') return 2;
	else if (ch == '+' || ch == '-') return 1;
	return 0;
}

int main()
{
	char str[105], result[105] = { 0 };
	int idx = 0;
	scanf("%s", str);
	stack<char>	S;

	for (int i = 0; str[i]; i++)
	{
		char ch = str[i];
		if (priority(ch)) // 연산자라면
		{
			while (!S.empty() && priority(ch) <= priority(S.top())) // 스택의 top에 있는 연산자의 우선순위가 ch보다 낮아질 때까지 pop
			{
				result[idx++] = S.top();
				S.pop();
			}
			S.push(ch);
		}
		else if (ch == '(') S.push(ch);
		else if (ch == ')') // 닫는 괄호 등장시
		{
			while (S.top() != '(') // 여는 괄호가 나올 떄까지 pop
			{
				result[idx++] = S.top();
				S.pop();
			}
			S.pop();
		}
		else result[idx++] = ch;
	}
	while (!S.empty())
	{
		result[idx++] = S.top();
		S.pop();
	}

	printf("%s", result);

	return 0;
}