#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;

bool isprime[10000 + 5];
vector<int> P;
int main()
{
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;

	int T;
	scanf("%d", &T);

	for (int i = 2; i * i <= 10000; i++)
		if (isprime[i])
			for (int j = i *i; j <= 10000; j += i)
				isprime[j] = false;

	for (int i = 2; i <= 10000; i++)
		if (isprime[i]) P.push_back(i);
	
	int n;
	vector<int> tmp;
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < P.size(); i++)
		{
			if (P[i] > n / 2) break;
			if (isprime[n - P[i]])
				tmp.push_back(P[i]), tmp.push_back(n - P[i]);
		}
		printf("%d %d\n", tmp[tmp.size() - 2], tmp[tmp.size() - 1]);
	}
	return 0;
}