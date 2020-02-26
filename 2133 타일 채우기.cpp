#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int D[35]; // D[i] : 3*i크기의 벽을 채우는 경우의 수

int main()
{
	scanf("%d", &N);
	
	// *** i가 홀수이면 만들 수 없음.
	D[2] = 3, D[4] = 11;
	for (int i = 6; i <= N; i += 2)
	{
		D[i] += D[i - 2] * 3;
		for (int j = i; j >= 4; j -= 2) // i - 4, i - 6, i - 8, ... 에 대해 고유 모양 2개씩 존재
		{
			D[i] += D[i - j] * 2;
		}

	}
	printf("%d", D[N]);
	return 0;
}