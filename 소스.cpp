#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

char str[105];
int alph[30];
int main()
{
	scanf("%s", str);

	int len = strlen(str);
	for (int i = 0; i < 30; i++) alph[i] = -1;
	for (int i = 0; i < len; i++)
	{
		if(alph[str[i] - 'a'] == -1)
			alph[str[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; i++) printf("%d ", alph[i]);
	return 0;
}