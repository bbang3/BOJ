#include <bits/stdc++.h>
using namespace std;

struct node
{
	int idx;
	int value;

	bool operator < (const node& b) const
	{
		if (value == b.value) return idx > b.idx;
		return value > b.value;
	}
};

const int MN = 1e5 + 5;
int arr[MN];
priority_queue<node> PQ;
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		PQ.push({ i, arr[i] });
	}

	int M;
	scanf("%d", &M);
	while (M--)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int i, v;
			scanf("%d %d", &i, &v);
			arr[i] = v;
			PQ.push({ i, arr[i] }); // 갱신된 노드 정보를 새로 추가
		}
		else
		{
			node mn = PQ.top();
			while (arr[mn.idx] != mn.value) // top 노드 정보가 현재 정보와 다름 -> 오래된 정보
			{
				PQ.pop();
				mn = PQ.top();
			}
			printf("%d\n", mn.idx);
		}
	}

	return 0;
}