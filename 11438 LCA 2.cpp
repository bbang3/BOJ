#include <bits/stdc++.h>
using namespace std;
// O(MlogN)
const int MN = 5e5 + 5;
const int INF = 2e9;
vector<int> graph[MN];
vector<int> trip; // 전위 순회 결과 저장 (노드번호는 입력을 따름)
int N;
int no2serial[MN], serial2no[MN];
int loc[MN]; // loc[i]: (입력 기준) i번 노드의 trip에서 위치
int nextSerial = 1;

void traverse(int cur, int prev)
{
	no2serial[cur] = nextSerial; // new numbering
	serial2no[nextSerial] = cur;
	nextSerial++;

	trip.push_back(no2serial[cur]);
	loc[cur] = trip.size();

	for (int next : graph[cur])
	{
		if (next == prev) continue;
		traverse(next, cur);
		trip.push_back(no2serial[cur]);
	}
}

struct segTree
{
	int tree[8 * MN];

	void init(int node, int start, int end)
	{
		if (start == end)
		{
			tree[node] = trip[start - 1]; // trip은 0-base
			return;
		}
		int mid = (start + end) / 2;
		init(node * 2, start, mid);
		init(node * 2 + 1, mid + 1, end);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
		return;

		//int leftmn = init(node * 2, start, mid), rightmn = init(node * 2 + 1, mid + 1, end);
		//return tree[node] = min(leftmn, rightmn);
	}

	int query(int node, int nodeLeft, int nodeRight, int left, int right)
	{
		if (right < nodeLeft || left > nodeRight) return INF;
		if (left <= nodeLeft && nodeRight <= right) return tree[node];

		int mid = (nodeLeft + nodeRight) / 2;
		int leftmn = query(node * 2, nodeLeft, mid, left, right);
		int rightmn = query(node * 2 + 1, mid + 1, nodeRight, left, right);
		return min(leftmn, rightmn);
	}
};
segTree sg;

int main()
{
	scanf("%d", &N);
	int a, b;
	for (int i = 1; i <= N - 1; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	traverse(1, -1);
	sg.init(1, 1, trip.size());

	int M;
	scanf("%d", &M);
	while (M--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int la = loc[a], lb = loc[b];
		if (la > lb) swap(la, lb);

		int par = sg.query(1, 1, trip.size(), la, lb);
		printf("%d\n", serial2no[par]);
	}
	return 0;
}