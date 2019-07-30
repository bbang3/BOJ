#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MX = 2 * 1e5 + 5;
const int MOD = 1e9 + 7;

struct query
{
	int v; int c;
	query() {}
	query(int v, int c) : v(v), c(c) {}

	bool operator < (query &a)
	{
		return c < a.c;
	}
};
int N, M, C;
int color[MX];
query Q[MX];

int num[MX], Rcolor[MX], child[MX]; 
// num[i] : i번 정점 ordering 후 번호 / Rcolor[i] : (ordering 후)i번 정점의 색깔 / child[i] : (ordering 후)i번 정점의 자식 개수
long long seg[4 * MX];
vector<int> G[MX], RG[MX]; // RG : Ordering 후 그래프
vector<int> cList[MX]; // cList[i] : 색깔이 i인 정점 목록
int idx = 1;

void numbering(int cur, int prev)
{
	num[cur] = idx++;
	Rcolor[num[cur]] = color[cur];

	for (int next : G[cur])
		if (next != prev) numbering(next, cur);
}

void countchild(int cur, int prev)
{
	for (int next : RG[cur])
		if (next != prev)
		{
			countchild(next, cur);
			child[cur] += child[next] + 1;
		}
}

void update(int idx, int node, int diff, int start, int end) // idx번 노드의 값을 diff만큼 증가시킴
{
	if (idx < start || idx > end) return;

	seg[node] += diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(idx, node * 2, diff, start, mid);
	update(idx, node * 2 + 1, diff, mid + 1, end);
}
// [left, right] 구간 합 구하기
long long sum(int node, int start, int end, int left, int right)
{
	if (right < start || left > end) return 0;
	if (left <= start && end <= right) return seg[node];

	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	scanf("%d %d %d", &N, &M, &C);
	for (int i = 1; i <= N; i++) scanf("%d", &color[i]);

	int src, dest;
	for (int i = 1; i <= N - 1; i++)
	{
		scanf("%d %d", &src, &dest);
		G[src].push_back(dest);
		G[dest].push_back(src);
	}

	numbering(1, -1);
	for (int i = 1; i <= N; i++)
		for (int next : G[i])
			RG[num[i]].push_back(num[next]); // 새로 numbering한 것으로 그래프 생성
	countchild(1, -1);

	for (int i = 1; i <= N; i++)
		cList[Rcolor[i]].push_back(i);
	

	for (int i = 1; i <= M; i++) scanf("%d %d", &Q[i].v, &Q[i].c);
	sort(Q + 1, Q + M + 1); // 쿼리를 color의 오름차순으로 정렬
	int i = 1;
	long long ans = 0;
	for (int color = 1; color <= C; color++) // 1번 color부터
	{
		for (int node : cList[color]) // color번 색 정점의 값을 1 늘림
			update(node, 1, 1, 1, N);

		for (; i <= M && Q[i].c == color; i++) // c = color인 쿼리에 대해
			ans = (ans + sum(1, 1, N, num[Q[i].v], num[Q[i].v] + child[num[Q[i].v]])) % MOD; // 구간 합을 구함
		// 새로 numbering한 그래프에서 [정점 번호, 정점 번호 + 자식 수] 구간의 합을 구하면 그게 쿼리의 답이 됨
	}
	printf("%lld", ans);

	return 0;
}