#include <cstdio>
#include <vector>
#include <string.h>
int main()
{
	char str[51] = { 0, };
	char ans[51] = { 0, };
	int alph[26] = { 0, };
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++)
	{
		alph[str[i] - 'A']++;
	}
	int j = 0;
	bool check = false;
	for (int i = 0; i < 26; i++)
	{
		if (alph[i] >= 2)
		{
			while (alph[i] >= 2)
			{
				ans[j] = ans[strlen(str) - j - 1] = i + 'A';
				j++;
				alph[i] -= 2;
			}
		}
		if (alph[i] == 1)
		{
			if (check || strlen(str) % 2 == 0)
			{
				printf("I'm Sorry Hansoo");
				return 0;
			}
			else
			{
				check = true;
				ans[strlen(str) / 2] = i + 'A';
			}
		}
		/*for (int i = 0; i < strlen(str); i++)
		{
		if (ans[i] == 0) printf("-");
		else printf("%c", ans[i]);
		}
		puts("");*/
	}
	ans[strlen(str) + 1] = 0;
	printf("%s", ans);
	return 0;
}