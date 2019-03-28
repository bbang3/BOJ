#include <stdio.h>
#include <string.h>
char words[105][105];
int N;

int isgroup(char str[])
{
	int len = strlen(str);
	char prev = str[0];
	bool check[30] = { 0, };

	check[prev - 'a'] = true;

	int ret = 1;
	for (int i = 1; i < len; i++)
	{
		if (str[i] != prev)
		{
			if (!check[str[i] - 'a'])
			{
				check[str[i] - 'a'] = true;
				prev = str[i];
			}
			else
			{
				return 0;
			}
		}
	}
	return 1;
}

int main()
{
	scanf("%d", &N);
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		scanf("%s", words[i]);
		ans += isgroup(words[i]);
	}

	printf("%d\n", ans);

	return 0;
}