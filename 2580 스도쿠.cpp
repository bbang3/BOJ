#include <cstdio>


int candy[11][11];
int totallen = 0;
bool flag = false;

void print()
{
	for (int i = 1; i <= 9; i++, puts(""))
		for (int j = 1; j <= 9; j++)
			printf("%d ", candy[i][j]);
}

void f(int i, int j)
{
	if (flag) return;
	if (i == 10)
	{
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++)
				if (candy[i][j] == 0) return;
		print();
		flag = true;
		return;
	}
	if (j == 10) f(i + 1, 1);

	if (candy[i][j] != 0)
	{
		f(i, j + 1);
		return;
	}

	bool check[10] = { 0, };
	for (int k = 1; k <= 9; k++)
		check[candy[i][k]] = check[candy[k][j]] = true;

	int ws = (j - 1) / 3 * 3, hs = (i - 1) / 3 * 3;

	for (int m = 1; m <= 3; m++)
	{
		for (int n = 1; n <= 3; n++)
			check[candy[hs + m][ws + n]] = true;
	}

	for (int n = 1; n <= 9; n++)
	{
		if (!check[n])
		{
			candy[i][j] = n;
			/*printf("(%d, %d) %d·Î º¯°æ\n", i, j, n);
			print();*/
			f(i, j + 1);
			candy[i][j] = 0;
		}
	}
}

int main()
{
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			scanf("%d", &candy[i][j]);
	//puts("");
	f(1, 1);
	return 0;
}