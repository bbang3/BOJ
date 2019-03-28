#include <cstdio>
#include <math.h>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

const int MN = 1000000 + 5;
int N, B, C;
char want[MN], str[MN];
string arr[MN];

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		getchar();
		scanf("%c", want + i);
	}
	for (int i = 1; i <= N; i++)
	{
		getchar();
		scanf("%c", str + i);
	}

	string s, tmp, target;
	for (int i = 1; i <= N; i++)
	{
		s += str[i];
		target += want[i];
		arr[i] = arr[i - 1] + str[N - i + 1];
	}
	tmp = s; 
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		string newstr = arr[i] + tmp;
		if (newstr == target) cnt++;
		tmp.pop_back();
	}
	
	int G = gcd(N, cnt);
	printf("%d/%d", cnt / G, N / G);
	return 0;
}