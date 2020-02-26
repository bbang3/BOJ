#include <cstdio>
#include <string.h>
int card[53][4]; // 스페이드 하트 다이아 클럽
char str[1001];
int p, k, h, t;
int main()
{
	scanf("%s", str);

	int idx = 0;

	while (idx < strlen(str))
	{
		char shape = str[idx];
		int num = (str[idx + 1] - '0') * 10 + (str[idx + 2] - '0');
		idx += 3;
		int i;
		switch (shape)
		{
		case 'P':
			i = 0;
			p++;
			break;
		case 'K':
			i = 1;
			k++;
			break;
		case 'H':
			i = 2;
			h++;
			break;
		case 'T':
			i = 3;
			t++;
			break;
		}
		if (card[num][i])
		{
			puts("GRESKA");
			return 0;
		}
		card[num][i]++;
	}
	printf("%d %d %d %d", 13 - p, 13 - k, 13 - h, 13 - t);
	return 0;
}