#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int arr[1000 + 5];
int D[1000 + 5]; // D[i] : i번째 요소를 마지막으로 하는 최장감소부분수열
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
	
	int ans = -1;
	for (int i = 1; i <= N; i++)
	{
		D[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if(arr[j] > arr[i])
				D[i] = max(D[i], D[j] + 1);

		}
			ans = max(ans, D[i]);
	}

	printf("%d", ans);

	return 0;
}