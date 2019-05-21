#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;  int num = 0;
	vector<int>dp;
	dp.push_back(-1);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;

		if (num > dp.back())
		{
			if (dp.back() == -1)
				dp.clear();

			dp.push_back(num);
		}

		else 
		{   
			auto pos = lower_bound(dp.begin(), dp.end(), num);
			
			*pos = num;
		}

	}

	cout << dp.size() << "\n";

	

	system("pause");
	return 0;
}