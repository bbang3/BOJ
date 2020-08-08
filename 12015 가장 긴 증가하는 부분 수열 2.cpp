#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MN = 1e6 + 5;
int arr[MN];
vector<int> lis;

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);

	lis.push_back(arr[1]);
	for (int i = 2; i <= N; i++)
	{ // lower_bound를 이용해 i번째 원소를 넣을 최적의 위치를 찾는다.
		int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
		if (idx >= lis.size()) lis.push_back(arr[i]);
		else lis[idx] = arr[i];
	}
	printf("%d", lis.size());

	return 0;
}