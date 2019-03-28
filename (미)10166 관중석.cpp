#include <cstdio>
#include <algorithm>
using namespace std;

int time[2001];

int main()
{
	int start, end;
	int sum = 0;
	scanf("%d %d", &start, &end);

	for (int num = start; num <= end; num++)
	{
		int count = num;
		time[num]++;
		for (int i = start; i <= num - 1; i++)
		{
			if (num % i == 0)
			{
				time[num]++;
				count -= (i - time[i] + 1);
			}
		}
		printf("%d\n", count);
		sum += count;
	}
	printf("%d", sum);
	return 0;
}