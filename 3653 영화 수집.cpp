#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> tree;
vector<int> V; // V[i] : i�� DVD�� ���� ��ġ
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
		
		// �� M���� ������ ��� �ΰ�, ���� ���� �ø� ������ ����� ������ �ڿ������� ��
		for (int i = 1; i <= N; i++) 
			update(i + M, 1), V[i] = i + M;

		int num, head = M;
		for (int i = 1; i <= M; i++)
		{
			scanf("%d", &num);
			printf("%d ", sum(V[num] - 1));

			update(V[num], -1); // ���� �ִ� �ڸ����� ���ٰ� ǥ��
			update(head, 1); // ���� �ø� �ڸ����� �ִٰ� ǥ��
			V[num] = head;
			head--;
		}
		puts("");
	}
	return 0;
}