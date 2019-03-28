#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int MN = 200000;
int N;

struct ball {
	int size;
	int color;
	int index;
	int sum;
}balls[200001];

bool cmp(ball a, ball b) { return a.size < b.size; }
bool cmp2(ball a, ball b) { return a.index < b.index; }

int s[MN + 1];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int c, s;
		scanf("%d %d", &c, &s);
		balls[i].color = c, balls[i].size = s, balls[i].index = i;
	}
	sort(balls, balls + N, cmp);

	int total = 0;
	for (int i = 0; i < N; i++)
	{
		s[balls[i].color] += balls[i].size;
		total += balls[i].size;
		balls[i].sum = total - s[balls[i].color];
	}
	sort(balls, balls + N, cmp2);
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", balls[i].sum);
	}
	return 0;
}