#include <cstdio>
#include <algorithm>
using namespace std;


const int MN = 1e6 + 5;
typedef long long ll;

struct line
{
	ll a;
	ll b; // 기울기 절편
};
ll S[MN], D[MN];
int N, A, B, C;
line stk[MN];

double xpoint(line i, line j) // 교점의 x좌표
{
	return (double)(j.b - i.b) / (i.a - j.a);
}

int main()
{
	scanf("%d %d %d %d", &N, &A, &B, &C);
	int n;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &n);
		S[i] = S[i - 1] + n;
	}

	int top = 0;
	stk[top++] = { B, 0 };
	for (int i = 1; i <= N; i++)
	{
		while (top >= 2 && 
			xpoint(stk[top], stk[top - 1]) > xpoint(stk[top - 1], stk[top - 2]))
			top--;
		stk[top++] = { -2 * A * S[i], A * S[i] * S[i] - B * S[i] + D[i] };
	}

	for (int i = 0; i < top - 1; i++)
	{
		if (xpoint(stk[i], stk[i + 1]) >= S[i])
		{
			D[i] = 
		}
	}

	return 0;
}