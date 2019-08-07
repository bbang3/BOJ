#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321
int N, M;
int cost[102][102];
//int previous[20001];
bool visit[102][102];
int arr[102][102];

bool issafe(int x, int y)
{
	return x >= 1 && x <= M && y >= 1 && y <= N;
}

struct node
{
	int x;
	int y;
	int w;
	node(int x, int y, int w) : x(x), y(y), w(w) {}

	bool operator < (node A)const { return w > A.w; }
};
priority_queue<node> PQ;

int main()
{
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cost[i][j] = INF;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", &arr[i][j]);

	int offset[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	int idx = 1;
	cost[1][1] = 0;
	PQ.push(node(1, 1, arr[1][1]));
	while (!PQ.empty())
	{
		node cur = PQ.top();
		PQ.pop();
		visit[cur.y][cur.x] = true;
		for (int k = 0; k < 4; k++)
		{
			int nextx = cur.x + offset[k][1], nexty = cur.y + offset[k][0];
			
			if (issafe(nextx, nexty) && !visit[nexty][nextx])
			{
				if (cost[cur.y][cur.x] + arr[nexty][nextx] < cost[nexty][nextx]) {
					cost[nexty][nextx] = cost[cur.y][cur.x] + arr[nexty][nextx]	;
					PQ.push(node(nextx,nexty,cost[nexty][nextx]));
				}
			}

		}
	}
	printf("%d", cost[N][M]);
	return 0;
}