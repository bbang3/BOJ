#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;
int arr[1001];
int D[1001]; // dp[i] = i��° ��ҷ� �����ϴ� LIS ����
int N;
int f(int start) {
	if (D[start] != -1) return D[start];
	D[start] = 1;
	for (int i = start + 1; i <= N; i++) {
		if (arr[i] > arr[start])
			D[start] = max(D[start], f(i) + 1);
	}
	return D[start];
}

void trace(vector<int> V, int idx, int ans)
{
	//printf("%d\n", idx);
	V.push_back(arr[idx]);
	if (V.size() == ans)
	{
		for (int n : V) printf("%d ", n);
		exit(0);
	}

	for (int i = idx + 1; i <= N; i++)
	{
		if (D[i] == D[idx] - 1) // �� ������ �����ϴ� ��� ����
		{
			trace(V, i, ans);
		}
	}
	V.pop_back();
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	memset(D, -1, sizeof(D));

	int ans = -1, si = 1;
	for (int i = 1; i <= N; i++)
	{
		int ret = f(i);
		if (ret > ans)
		{
			ans = ret;
			si = i;
		}
	}
	printf("%d\n", ans);
	vector<int> V;
	trace(V, si, ans);
	return 0;
}