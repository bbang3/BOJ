#include <cstdio>
#include <queue>
using namespace std;
int N, d, k, c;
int arr[30001];
int time[3001];
queue<int> Q;
int main()
{
	scanf("%d%d%d%d", &N, &d, &k, &c);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	int ans = 0, temp = 1; // ÄíÆù
	time[c] = 1;
	for (int i = 0; i < k; i++)
	{
		Q.push(arr[i]);
		if (!time[arr[i]]) {
			temp++;
		}
		time[arr[i]]++;
	}
	ans = temp;
	
	int loop = 0, i = k;
	while(loop < N)
	{
		int front = Q.front();
		Q.pop();
		if (front != c)
		{
			time[front]--;
			if (!time[front]) temp--;
		}
		Q.push(arr[i]);
		if (!time[arr[i]]) temp++;
		time[arr[i]]++;

		ans = temp > ans ? temp : ans;
		loop++;
		i = (i + 1) % N;
	}
	printf("%d", ans);
	return 0;
}