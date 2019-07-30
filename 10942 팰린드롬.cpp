#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

int N, M;
int arr[2000 + 5];
int D[2000 + 5][2000 + 5]; // D[i][j] : arr[i] ~ arr[j]가 팰린드롬이면 1, 아니면 0
// D[i][j] = (arr[i] == arr[j] 이고 D[i + 1][j - 1] == 1)

bool f(int s, int e)
{
	if (s >= e) return D[s][e] = 1;
	if (D[s][e] != -1) return D[s][e];

	return D[s][e] = (arr[s] == arr[e] && f(s + 1, e - 1));
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
	memset(D, -1, sizeof(D));
	//for (int i = 1; i <= N; i++)
	//	for (int j = i; j <= N; j++)
	//		D[i][j] = f(i, j);


	//for (int i = 1; i <= N; i++, puts(""))
	//	for (int j = 1; j <= N; j++)
	//		printf("%2d ", D[i][j]);
	scanf("%d", &M);	
	while (M--) 
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", f(a, b) == 1);
	}

	return 0;
}