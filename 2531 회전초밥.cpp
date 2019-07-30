#include <cstdio>
#include <queue>
using namespace std;
int N, d, k, color;
int arr[30001];
int time[3001];
queue<int> M;
int main()
{
	scanf("%d%d%d%d", &N, &d, &k, &color);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	int ans = 0, temp = 1; // ÄíÆù
	time[color] = 1;
	for (int i = 0; i < k; i++)
	{
		M.push(arr[i]);
		if (!time[arr[i]]) {
			temp++;
		}	

		time[arr[i]]++;
	}
	ans = temp;
	
	int loop = 0, i = k;
	while(loop < N)
	{
		int front = M.front();
		M.pop();
		if (front != color)
		{
			time[front]--;
			if (!time[front]) temp--;
		}
		M.push(arr[i]);
		if (!time[arr[i]]) temp++;
		time[arr[i]]++;

		ans = temp > ans ? temp : ans;
		loop++;
		i = (i + 1) % N;
	}
	printf("%d", ans);
	return 0;
}