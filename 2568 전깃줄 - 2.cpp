#include <bits/stdc++.h>
using namespace std;

struct Line
{
	int s;
	int e;

	bool operator < (Line& a)
	{
		return s < a.s;
	}
};

const int MN = 1e5 + 5;
Line wire[MN];
int N;
int occur[MN]; // occur[i]: i번째 원소가 LIS 찾는 과정에서 들어가게 되는 위치
bool ok[MN];

void trace(int i, int occuridx)
{
	if (i == 0) return;
	if (occur[i] == occuridx)
	{
		ok[i] = true;
		trace(i - 1, occuridx - 1);
		return;
	}
	trace(i - 1, occuridx);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d %d", &wire[i].s, &wire[i].e);
	sort(wire + 1, wire + N + 1);

	vector<int> lis;
	for (int i = 1; i <= N; i++)
	{
		int value = wire[i].e;
		int idx = upper_bound(lis.begin(), lis.end(), value) - lis.begin();
		occur[i] = idx;

		if (idx >= lis.size()) lis.push_back(value);
		else lis[idx] = value;
	}
	trace(N, lis.size() - 1);

	printf("%d\n", N - lis.size());
	for (int i = 1; i <= N; i++)
		if (!ok[i]) printf("%d\n", wire[i].s);

	return 0;
}