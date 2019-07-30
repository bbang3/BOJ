#include <cstdio>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
using namespace std;

vector<vector<int> > dist;
int p[100005];
map<int, int> M;
int N, S;

void bfs()
{
	queue<int> Q;
	vector<int> dist(N + 5, 987654321);
	vector<bool> visited(N + 5, false);
	Q.push(1);
	dist[1] = 0;
	memset(p, -1, sizeof(p)); // -1�� �ʱ�ȭ�Ͽ� �Ŀ� ��ΰ� ���� ��츦 �����ϱ� ���� ����Ѵ�.
	p[1] = 0; // par : predecessor ����
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		visited[cur] = true;
		for (int next : dist[cur])
		{
			if (!visited[next] && dist[next] > dist[cur] + 1) // && ���� ���� �� �ٿ���� ��. �ð��ʰ� ��.
			{
				Q.push(next);
				dist[next] = dist[cur] + 1;
				p[next] = cur;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &S);
	dist.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		int num = 0;
		for (int j = 1; j <= S; j++)
		{
			int t;
			scanf("%1d", &t);
			num = num * 2 + t; // �Է¹��� ���� 10������ ��ȯ�Ѵ�.
		}
		M.insert({ num, i }); //�ε��� ������ �Բ� map�� �ִ´�. map�� �ִ� ����->logN�� ã�� ����
	}

	for (auto i : M)
	{
		for (int j = 0; j < S; j++)
		{
			auto it = M.find(i.first ^ 1 << j); // ��ȣ ���� ������ �� ���ڵ��� ��Ʈ 1�ڸ��� �ٲپ� ���� �۾�

			if (it != M.end()) // find�� ���Ұ� ���� ��� end�� ��ȯ�Ѵ�.
			{
				int dest = it->second;

				dist[i.second].push_back(dest);
			}
		}
	}

	int Q;
	scanf("%d", &Q);
	bfs(); // bfs�� ������.
	while (Q--)
	{
		int j;
		scanf("%d", &j);

		if (p[j] == -1) puts("-1"); // -1�� ��� ��ΰ� ���ٴ� ��.
		else
		{
			vector<int> S;
			int t = j;
			while (t != 0) // predecessor�� �̿��Ͽ� �ִ� ��θ� ���Ѵ�. �������� predecessor�� 0�̹Ƿ� �ùٸ��� ���� ����.
			{
				S.push_back(t);
				t = p[t];
			}
			for (int i = S.size() - 1; i >= 0; i--)
				printf("%d ", S[i]);
			puts("");
		}
	}
	return 0;
}