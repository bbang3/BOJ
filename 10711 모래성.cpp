#include <bits/stdc++.h>
using namespace std;

const int MX = 1000 + 5;
int H, W;
char mp[MX][MX];

struct Pos
{
	int i;
	int j;
};

bool safe(int i, int j)
{
	return i >= 1 && i <= H && j >= 1 && j <= W;
}

int getcnt(int i, int j) // (i, j)와 인접한 .의 개수
{
	int cnt = 0;
	for (int di = -1; di <= 1; di++)
		for (int dj = -1; dj <= 1; dj++)
		{
			if (safe(i, j) && mp[i + di][j + dj] == '.')
			{
				cnt++;
			}
		}
	return cnt;
}

int main()
{
	scanf("%d %d", &H, &W);

	for (int i = 1; i <= H; i++)
		scanf("%s", mp[i] + 1);

	vector<Pos> Q;
	bool visit[MX][MX] = { false };
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			if (mp[i][j] != '.')
			{
				if (getcnt(i, j) >= mp[i][j] - '0') // 무너질 수 있는 모래성만 저장
				{
					Q.push_back({ i, j });
					visit[i][j] = true;
				}
			}

	int ans = 0;
	while (!Q.empty())
	{
		for (Pos cur : Q)
		{
			mp[cur.i][cur.j] = '.'; // 모래성을 무너뜨림
		}

		vector<Pos> nextQ;
		for (Pos cur : Q) // 이후 인접한 모래성을 검사하여 무너뜨릴 수 있는 모래성이 있는지 탐색
		{
			for (int i = cur.i - 1; i <= cur.i + 1; i++)
				for (int j = cur.j - 1; j <= cur.j + 1; j++)
				{
					if (safe(i, j) && !visit[i][j] && mp[i][j] != '.' && getcnt(i, j) >= mp[i][j] - '0')
					{
						nextQ.push_back({ i, j });
						visit[i][j] = true;
					}
				}
		}
		Q = nextQ;
		ans++;
	}

	printf("%d", ans);

	return 0;
}
