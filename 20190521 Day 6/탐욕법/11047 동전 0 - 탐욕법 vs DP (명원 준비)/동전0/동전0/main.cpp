#include <iostream>
#include <vector>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;  vector<int>number;
	int var;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> var;
		number.push_back(var);
	}
	
	int count = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		if ((K / number[i] != 0))
		{
			count += K / number[i];
			K = K % number[i];
		}
	}

	cout << count;

	system("pause");

	return 0;
}