#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

const int MN = 1e5 + 5;
int N;
int arr[MN][3];
int mxscore[2][3]; // mxscore[i][j]: (i, j)�� ���������� ������ ���� �� �ִ� �ִ� ����
int mnscore[2][3]; // mnscore[i][j]: (i, j)�� ���������� ������ ���� �� �ִ� �ּ� ����
// sliding window ����

// mxscore[i][j] = max(mxscore[i - 1][n] + arr[i][j]) where n = j �Ǵ� j�� ������ ��
// base case: i == 1 -> return arr[i][j]
// *** i��° ���� ���� i-1��° �࿡�� ���� �����Ƿ� �� 2���� ���� �� �ִ�.

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	memset(mxscore, -1, sizeof(mxscore));
	memset(mnscore, -1, sizeof(mnscore));

	mxscore[0][0] = mnscore[0][0] = arr[0][0];
	mxscore[0][1] = mnscore[0][1] = arr[0][1];
	mxscore[0][2] = mnscore[0][2] = arr[0][2];
	int cur, prev;
	for (int i = 1; i < N; i++)
	{
		cur = i % 2, prev = !cur;
		mxscore[cur][0] = max(mxscore[prev][0], mxscore[prev][1]) + arr[i][0];
		mxscore[cur][1] = max({ mxscore[prev][0], mxscore[prev][1], mxscore[prev][2] }) + arr[i][1];
		mxscore[cur][2] = max(mxscore[prev][1], mxscore[prev][2]) + arr[i][2];

		mnscore[cur][0] = min(mnscore[prev][0], mnscore[prev][1]) + arr[i][0];
		mnscore[cur][1] = min({ mnscore[prev][0], mnscore[prev][1], mnscore[prev][2] }) + arr[i][1];
		mnscore[cur][2] = min(mnscore[prev][1], mnscore[prev][2]) + arr[i][2];
	}
	int mxans = max({ mxscore[cur][0], mxscore[cur][1], mxscore[cur][2] });
	int mnans = min({ mnscore[cur][0], mnscore[cur][1], mnscore[cur][2] });
	printf("%d %d", mxans, mnans);

	return 0;
}