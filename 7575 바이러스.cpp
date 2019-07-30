#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <string.h>
int N, S;

int arr[101][1001];
int pattern[1001];
int pattern2[1001];
int pi[1001];
int pi2[1001];
bool isexist[1001];

void generate_pi(int *p, int *pi, int len) {
	int m = len;
	int i, j = 1;
	pi[1] = 0;

	for (i = 2; i <= m; ++i) {
		while (j > 1 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			++j;
		pi[i] = j;
	}
}

bool kmp(int *text, int *pattern, int *pi, int textlen, int patternlen) {
	int n = textlen;
	int m = patternlen;
	int i, j = 1;

	for (int i = 1; i <= n; ++i) {
		while (j > 1 && text[i] != pattern[j])
			j = pi[j - 1];
		if (text[i] == pattern[j]) {
			if (j == m)
				return true;
			else
				j++;
		}
	}
	return false;
}

bool check()
{
	for (int i = 2; i <= N; i++) {
		if (!isexist[i]) return false;
	}
	return true;
}

int main()
{
	scanf("%d %d", &N, &S);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i][0]);
		for (int j = 1; j <= arr[i][0]; j++)
			scanf("%d", &arr[i][j]);
	}

	int k = S;
	for (int i = 1; i <= arr[1][0] - k + 1; i++)
	{
		int idx = 1;
		memset(pattern, 0, sizeof(pattern)); memset(pattern2, 0, sizeof(pattern2)); memset(pi, 0, sizeof(pi));
		memset(pi, 0, sizeof(pi)); memset(pi2, 0, sizeof(pi2));
		for (int j = i; j <= i + k - 1; j++) pattern[idx] = arr[1][j], pattern2[k - idx++ + 1] = arr[1][j];
		/*for (int a = 1; a <= k; a++) printf("%d ", pattern[a]); puts("");
		for (int a = 1; a <= k; a++) printf("%d ", pattern2[a]); puts("");*/
		generate_pi(pattern, pi, k);
		for (int t = 2; t <= N; t++)
		{
			if (kmp(arr[t], pattern, pi, arr[t][0], k))
				isexist[t] = true;
		}
		generate_pi(pattern2, pi2, k);
		for (int t = 2; t <= N; t++)
		{
			if (kmp(arr[t], pattern2, pi2, arr[t][0], k))
				isexist[t] = true;
		}

		if (check()) {
			puts("YES"); return 0;
		}
	}
	puts("NO");
	return 0;
}