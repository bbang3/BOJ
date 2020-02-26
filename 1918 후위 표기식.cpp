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
		if (priority(ch)) // �����ڶ��
		{
			while (!S.empty() && priority(ch) <= priority(S.top())) // ������ top�� �ִ� �������� �켱������ ch���� ������ ������ pop
			{
				result[idx++] = S.top();
				S.pop();
			}
			S.push(ch);
		}
		else if (ch == '(') S.push(ch);
		else if (ch == ')') // �ݴ� ��ȣ �����
		{
			while (S.top() != '(') // ���� ��ȣ�� ���� ������ pop
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