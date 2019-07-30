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
	memset(p, -1, sizeof(p)); // -1로 초기화하여 후에 경로가 없는 경우를 제어하기 위해 사용한다.
	p[1] = 0; // par : predecessor 저장
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		visited[cur] = true;
		for (int next : dist[cur])
		{
			if (!visited[next] && dist[next] > dist[cur] + 1) // && 뒤의 수식 꼭 붙여줘야 함. 시간초과 남.
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
			num = num * 2 + t; // 입력받은 수를 10진수로 변환한다.
		}
		M.insert({ num, i }); //인덱스 정보와 함께 map에 넣는다. map에 넣는 이유->logN에 찾기 위해
	}

	for (auto i : M)
	{
		for (int j = 0; j < S; j++)
		{
			auto it = M.find(i.first ^ 1 << j); // 괄호 안의 수식이 각 숫자들의 비트 1자리씩 바꾸어 보는 작업

			if (it != M.end()) // find는 원소가 없을 경우 end를 반환한다.
			{
				int dest = it->second;

				dist[i.second].push_back(dest);
			}
		}
	}

	int Q;
	scanf("%d", &Q);
	bfs(); // bfs를 돌린다.
	while (Q--)
	{
		int j;
		scanf("%d", &j);

		if (p[j] == -1) puts("-1"); // -1일 경우 경로가 없다는 뜻.
		else
		{
			vector<int> S;
			int t = j;
			while (t != 0) // predecessor을 이용하여 최단 경로를 구한다. 시작점의 predecessor가 0이므로 올바르게 종료 가능.
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