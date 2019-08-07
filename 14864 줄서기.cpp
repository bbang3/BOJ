#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;
#define MAX 100000
int arr[MAX + 1];
int main() {
	int N, a;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
	std::sort(arr + 1, arr + N + 1, std::greater<int>());
	int m = 0;
	for (int i = 1; i <= N; i++)
	{
		m = arr[i] * i > m ? arr[i] * i : m;
	}
	printf("%d", m);
	return 0;
}