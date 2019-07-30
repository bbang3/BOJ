#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 300000 + 5;
int N, L;
int A[MN], B[MN];
int p[MN], use[MN]; // use[i] : i번째 서랍에 들어 있는 술병

int find(int n) { return p[n] == n ? n : p[n] = find(p[n]); }

void merge(int a, int b)
{
	a = find(a), b = find(b);
	p[a] = b;
}

int main()
{
	scanf("%d %d", &N, &L);
	for (int i = 1; i <= L; i++) p[i] = i;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &A[i], &B[i]);
		if (!use[A[i]])
		{
			use[A[i]] = i;
			merge(A[i], B[i]);
		}
		else if (!use[B[i]])
		{
			use[B[i]] = i;
			merge(B[i], A[i]);
		}
		else
		{
			int pa = find(A[i]), pb = find(B[i]);
			if (!use[pa])
			{
				use[pa] = i;
				merge(A[i], B[i]);
			}
			else if(!use[pb])
			{
				use[pb] = i;
				merge(B[i], A[i]);
			}
			else
			{
				puts("SMECE");
				continue;
			}
		}
		puts("LADICA");
		merge(A[i], B[i]);
		//for (int i = 1; i <= L; i++) printf("%d ", p[i]);
		//puts("");
	}


	return 0;
}