#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

int M;
int main()
{
	scanf("%d", &M);
	char command[20]; int x;
	unsigned int S = 0;
	while (M--)
	{
		scanf("%s", command);
		if (!strcmp(command, "all"))
		{
			for (int i = 0; i < 20; i++)
				S |= 1 << i;
		}
		else if (!strcmp(command, "empty")) S = 0;
		else
		{
			scanf("%d", &x);
			if (!strcmp(command, "add"))
			{
				S |= 1 << (x - 1);
			}
			else if (!strcmp(command, "remove"))
			{
				S &= ~(1 << (x - 1));
			}
			else if (!strcmp(command, "check"))
			{
				printf("%d\n", (S & (1 << (x - 1))) == 0 ? 0 : 1);
			}
			else if (!strcmp(command, "toggle"))
			{
				S ^= (1 << (x - 1));
			}
		}
	}
	return 0;
}