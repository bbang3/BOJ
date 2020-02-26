#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int arr[10], sum = 0;
	for (int i = 1; i <= 9; i++)
		scanf("%d", arr + i), sum += arr[i];

	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 9; j++)
			if (sum - arr[i] - arr[j] == 100)
			{
				for (int k = 1; k <= 9; k++)
				{
					if (k == i || k == j) continue;
					printf("%d\n", arr[k]);
				}
				return 0;
			}

	return 0;
}