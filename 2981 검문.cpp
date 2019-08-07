#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
// ��� i�� ���� a_i = n_i * m + k�̴�.
// ��� i, j�� ���� a_i - a_j = (n_i - n_j) * m�̹Ƿ�
// m�� ������ �� ������ ������ ������� �ȴ�.
int main()
{
	int N;
	int arr[100 + 5];
	vector<int> V;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", arr + i);

	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++)
			V.push_back(abs(arr[i] - arr[j]));

	int G = gcd(V[0], V[1]);
	for (int i = 2; i < V.size(); i++)
		G = gcd(G, V[i]);

	vector<int> fact;
	for (int i = 2; i*i <= G; i++)
		if (G % i == 0)
		{
			fact.push_back(i);
			if(i * i != G) fact.push_back(G / i);
		}
	sort(fact.begin(), fact.end());
	for (int n : fact) printf("%d ", n);
	printf("%d", G);
	return 0;
}