#include <iostream>
#include <vector>

using namespace std;

bool isPalin(vector<int>nums)
{
	int size = nums.size();

	for (int i = 0; i < size / 2; i++)
	{
		if (nums[i] != nums[size - i - 1]) return false;
	}

	return true;

}

int main(void)
{
	int n;

	while (1) {

		cin >> n;
		if (n == 0) break;

		vector<int>v;
		while (n > 0)
		{
			v.push_back(n % 10);
			n /= 10;
		}

		if (isPalin(v)) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
	return 0;	
}