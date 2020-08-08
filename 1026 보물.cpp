#include <bits/stdc++.h>
using namespace std;

int A[50], B[50];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for (int i = 1; i <= N; i++) scanf("%d", &B[i]);
	sort(A + 1, A + N + 1);
	sort(B + 1, B + N + 1);

	int S = 0;
	for (int i = 1; i <= N; i++)
		S += A[i] * B[N - i + 1];

	printf("%d", S);

	return 0;
}