#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321
const int MN = 2000 + 5;
const int MK = 1e5 + 5;
struct pos {
	int x;
	int y;
	pos() {}
	pos(int x, int y) : x(x), y(y) {}
};

int N, S, ans = 0;
int time[MN][MN], num[MN][MN], parent[MN * MN];
// time[i][j] : 문명이 해당 격자로 퍼지는 (최소)시간, num[i][j] : 해당 격자의 고유번호, parent[i][j] : 해당 격자의 root
bool visit[MN][MN];
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
queue<pos> M;

int issafe(int x, int y)
{
	return x >= 1 && x <= N && y >= 1 && y <= N;
}

int par(int cur)
{
	if (parent[cur] == cur) return cur;
	return parent[cur] = par(parent[cur]);
}

int main()
{
	scanf("%d %d", &N, &S);
	int n = 0;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
		num[i][j] = ++n, time[i][j] = INF; // 격자마다 고유번호를 매기고, time을 무한대로 초기화
	for (int i = 1; i <= N * N; i++) parent[i] = i; // 처음엔 모두 parent는 자신

	for (int i = 1; i <= S; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		time[y][x] = 0; // 문명의 발생지는 time 0
		M.push(pos(x, y)); // 발생지부터 bfs 시작
	}
	
	int groupcnt = 0; // 현재 존재하는 다른 그룹의 개수
	while (1)
	{
		while (!M.empty())
		{
			int curx = M.front().x, cury = M.front().y;
			M.pop();

			if (time[cury][curx] != ans) // 하루가 바뀔 때마다 ans+1 하기 위한 코드
			{
				M.push(pos(curx, cury));
				break;
			}
			visit[cury][curx] = true; // 방문 표시
			groupcnt++; // 일단 새 그룹으로 보고 +1

			for (int i = 0; i < 4; i++)
			{
				int nx = curx + dx[i], ny = cury + dy[i]; // 현재 격자에서 상하좌우 검사
				if (!issafe(nx, ny)) continue;

				if (visit[ny][nx]) // 이미 방문한 격자라면 -> 퍼지면서 만난 것
				{
					int pn = par(num[ny][nx]), pc = par(num[cury][curx]); // parent 비교

					if (pn != pc) // parent가 다르면 -> 서로 다른 문명에서 퍼진 것
					{
						parent[pn] = pc; // 문명 합침
						groupcnt--; // 그룹 개수 -1
					}
				}
				else if(time[ny][nx] == INF) // 처음 방문하는 격자라면
				{
					time[ny][nx] = time[cury][curx] + 1; // 방문할 격자 = 현재 격자 +1일
					M.push(pos(nx, ny)); // 큐에 넣음
				}
			}
		}
		if (groupcnt == 1) break; // 그룹이 하나라면 다 합쳐진 것이므로 반복 종료
		ans++; // 종료될 때까지 하루하루 늘려 감
	}
	printf("%d", ans);

	return 0;
}