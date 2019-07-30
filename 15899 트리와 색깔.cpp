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
// num[i] : i�� ���� ordering �� ��ȣ / Rcolor[i] : (ordering ��)i�� ������ ���� / child[i] : (ordering ��)i�� ������ �ڽ� ����
long long seg[4 * MX];
vector<int> G[MX], RG[MX]; // RG : Ordering �� �׷���
vector<int> cList[MX]; // cList[i] : ������ i�� ���� ���
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

void update(int idx, int node, int diff, int start, int end) // idx�� ����� ���� diff��ŭ ������Ŵ
{
	if (idx < start || idx > end) return;

	seg[node] += diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(idx, node * 2, diff, start, mid);
	update(idx, node * 2 + 1, diff, mid + 1, end);
}
// [left, right] ���� �� ���ϱ�
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
			RG[num[i]].push_back(num[next]); // ���� numbering�� ������ �׷��� ����
	countchild(1, -1);

	for (int i = 1; i <= N; i++)
		cList[Rcolor[i]].push_back(i);
	

	for (int i = 1; i <= M; i++) scanf("%d %d", &Q[i].v, &Q[i].c);
	sort(Q + 1, Q + M + 1); // ������ color�� ������������ ����
	int i = 1;
	long long ans = 0;
	for (int color = 1; color <= C; color++) // 1�� color����
	{
		for (int node : cList[color]) // color�� �� ������ ���� 1 �ø�
			update(node, 1, 1, 1, N);

		for (; i <= M && Q[i].c == color; i++) // c = color�� ������ ����
			ans = (ans + sum(1, 1, N, num[Q[i].v], num[Q[i].v] + child[num[Q[i].v]])) % MOD; // ���� ���� ����
		// ���� numbering�� �׷������� [���� ��ȣ, ���� ��ȣ + �ڽ� ��] ������ ���� ���ϸ� �װ� ������ ���� ��
	}
	printf("%lld", ans);

	return 0;
}