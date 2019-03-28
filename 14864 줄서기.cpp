#include <cstdio>
#include <algorithm>
using namespace std;

const int MN = 100000 + 5;

int N, M;
bool time[MN];
int num[MN]; 

int main()
{
	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= N; i++)
	{
		num[i] = i;
		// 카드 번호가 오름차순으로 되어 있다고 가정
	}

	while (M--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		num[a]++, num[b]--; // 학생a보다 작은 사람이 생겼으므로 num[a] + 1, 학생 b보다 큰 사람이 생겼으므로 num[b] + 1
	}
	for (int i = 1; i <= N; i++)
	{
		if (time[num[i]]) // 카드 번호가 겹침 -> 모순 발생
		{
			puts("-1");
			return 0;
		}
		time[num[i]] = 1;
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", num[i]);
	return 0;
}