#include <cstdio>
// inchworm 알고리즘
int N;
int arr[100001];
bool time[100001];
int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);

	int left = 1, right = 1;
	int curlen = 1;
	long long sum = 0;
	while (right <= N)
	{
		if(time[arr[right]])
		{
			time[arr[left]] = 0;
			left++;
			while (arr[left] == arr[right] && left < right)
			{
				left++;
			}
		}
		time[arr[right]] = 1;
		sum += right - left + 1;
		right++;
	}
	printf("%lld", sum);
	return 0;
}