#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	string parString;
	cin >> parString;

	stack<char> stk;
	int ans = 0, mult = 1;
	bool possible = true;
	for (int i = 0; i < parString.length(); i++)
	{
		if (parString[i] == '(')
		{
			stk.push('(');
			mult *= 2;
		}
		else if (parString[i] == '[')
		{
			stk.push('[');
			mult *= 3;
		}
		else if (parString[i] == ')')
		{
			if (stk.empty() || stk.top() != '(')
			{
				possible = false;
				break;
			}
			if (parString[i - 1] == '(')
				ans += mult;
			mult /= 2;
			stk.pop();

		}
		else if (parString[i] == ']')
		{
			if (stk.empty() || stk.top() != '[')
			{
				possible = false;
				break;
			}
			if (parString[i - 1] == '[')
				ans += mult;
			mult /= 3;
			stk.pop();
		}
		//cout << ans << " ";
	}
	if (stk.empty() && possible) cout << ans;
	else cout << 0;

	return 0;
}