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
// time[i][j] : ������ �ش� ���ڷ� ������ (�ּ�)�ð�, num[i][j] : �ش� ������ ������ȣ, parent[i][j] : �ش� ������ root
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
		num[i][j] = ++n, time[i][j] = INF; // ���ڸ��� ������ȣ�� �ű��, time�� ���Ѵ�� �ʱ�ȭ
	for (int i = 1; i <= N * N; i++) parent[i] = i; // ó���� ��� parent�� �ڽ�

	for (int i = 1; i <= S; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		time[y][x] = 0; // ������ �߻����� time 0
		M.push(pos(x, y)); // �߻������� bfs ����
	}
	
	int groupcnt = 0; // ���� �����ϴ� �ٸ� �׷��� ����
	while (1)
	{
		while (!M.empty())
		{
			int curx = M.front().x, cury = M.front().y;
			M.pop();

			if (time[cury][curx] != ans) // �Ϸ簡 �ٲ� ������ ans+1 �ϱ� ���� �ڵ�
			{
				M.push(pos(curx, cury));
				break;
			}
			visit[cury][curx] = true; // �湮 ǥ��
			groupcnt++; // �ϴ� �� �׷����� ���� +1

			for (int i = 0; i < 4; i++)
			{
				int nx = curx + dx[i], ny = cury + dy[i]; // ���� ���ڿ��� �����¿� �˻�
				if (!issafe(nx, ny)) continue;

				if (visit[ny][nx]) // �̹� �湮�� ���ڶ�� -> �����鼭 ���� ��
				{
					int pn = par(num[ny][nx]), pc = par(num[cury][curx]); // parent ��

					if (pn != pc) // parent�� �ٸ��� -> ���� �ٸ� ������ ���� ��
					{
						parent[pn] = pc; // ���� ��ħ
						groupcnt--; // �׷� ���� -1
					}
				}
				else if(time[ny][nx] == INF) // ó�� �湮�ϴ� ���ڶ��
				{
					time[ny][nx] = time[cury][curx] + 1; // �湮�� ���� = ���� ���� +1��
					M.push(pos(nx, ny)); // ť�� ����
				}
			}
		}
		if (groupcnt == 1) break; // �׷��� �ϳ���� �� ������ ���̹Ƿ� �ݺ� ����
		ans++; // ����� ������ �Ϸ��Ϸ� �÷� ��
	}
	printf("%d", ans);

	return 0;
}