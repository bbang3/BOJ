#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> tree;
vector<int> V; // V[i] : i번 DVD의 현재 위치
int sz;

void init(int n)
{ 
	for (sz = 1; sz <= n; sz <<= 1); 
	tree.resize(sz + 5);
}

void update(int pos, int diff)
{
	while (pos <= sz)
	{
		tree[pos] += diff;
		pos += (pos & -pos);
	}
}

int sum(int pos)
{
	int ret = 0;
	while (pos > 0)
	{
		ret += tree[pos];
		pos -= (pos & -pos);
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		V.clear(); tree.clear();
		V.resize(N + M + 5);
		init(N + M);
		
		// 앞 M개의 공간을 비워 두고, 빼서 위로 올릴 때마다 비워둔 공간을 뒤에서부터 씀
		for (int i = 1; i <= N; i++) 
			update(i + M, 1), V[i] = i + M;

		int num, head = M;
		for (int i = 1; i <= M; i++)
		{
			scanf("%d", &num);
			printf("%d ", sum(V[num] - 1));

			update(V[num], -1); // 원래 있던 자리에는 없다고 표시
			update(head, 1); // 새로 올린 자리에는 있다고 표시
			V[num] = head;
			head--;
		}
		puts("");
	}
	return 0;
}