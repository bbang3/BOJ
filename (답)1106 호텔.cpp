#include <cstdio>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1000000000;

int N, C, wine[20], earn[20], D[21][1001];

int hotel(int pos, int dest) {
	int &ret = D[pos][dest];
	if (ret != -1) return ret;
	if (pos == N) return ret = (dest ? IMPOSSIBLE : 0);

	ret = hotel(pos + 1, dest);
	if (dest > 0) ret = min(ret, hotel(pos, max(dest - earn[pos], 0)) + wine[pos]);
	return ret;
}

int main() {
	scanf("%d %d", &C, &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", wine + i, earn + i);
	memset(D, -1, sizeof(D));
	printf("%d\n", hotel(0, C));
}