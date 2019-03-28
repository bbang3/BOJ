#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct H
{
	int a;
	int b;

	H() {}
	H(int a, int b) : a(a), b(b) {}

	bool operator < (const H &t)
	{
		return a < t.a;
	}
};

int N, M;
int arr[3][200000 + 5];
H matrix[200000 + 5];
int D[200000 + 5];
vector<int> L;

int main()
{
	scanf("%d %d", &M, &N);

	for (int i = 0; i < M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int ans = 0;
	if (M == 2)
	{
		for (int i = 1; i <= N; i++)
		{
			matrix[i] = H(arr[0][i], arr[1][i]);
		}
		sort(matrix + 1, matrix + 1 + N);

		L.push_back(-1);
		for (int i = 1; i <= N; i++)
		{
			if (matrix[i].b > L.back()) 
			{
				L.push_back(matrix[i].b);
				ans++;
			}
			else
			{
				auto it = lower_bound(L.begin(), L.end(), matrix[i].b);
				*it = matrix[i].b;
			}
		}
	}
	printf("%d", ans);
	return 0;
}