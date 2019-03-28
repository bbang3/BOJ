#include <cstdio>

int N;
int tree[500001];
int sequence[500001];
int time[1000001];

int sum(int i) // 1~i번째 위치까지의 합
{
	int s = 0;
	while (i > 0)
	{
		s += tree[i];
		i -= (i & -i);
	}
	return s;
}

void update(int i, int num)
{
	while (i <= N)
	{
		tree[i] += num;
		i += (i & -i);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int s;
		scanf("%d", &s);
		time[s] = i;
	}
	
	for (int i = 1; i <= N; i++)
	{
		int num;
		scanf("%d", &num);
		sequence[time[num]] = i;
	}

	long long ans = 0;
	for (int i = 1; i <= N; i++)
	{
		update(sequence[i], 1);
		ans += sum(N) - sum(sequence[i]);
	}
	printf("%lld", ans);
	
	return 0;
}