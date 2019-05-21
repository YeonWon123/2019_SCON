#include <iostream>
using namespace std;

int coin[101];
int DP[10001];


int main (void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, k;
	
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}

	DP[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if(j >= coin[i])
			DP[j] += DP[j - coin[i]];
		}
	}

	cout << DP[k];


	system("pause");
	return 0;
}