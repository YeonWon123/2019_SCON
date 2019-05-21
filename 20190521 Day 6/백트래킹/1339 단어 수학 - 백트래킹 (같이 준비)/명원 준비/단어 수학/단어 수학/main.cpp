#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string>Alpha;
int STore[26] = { 0 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;    string input;

	cin >> N;

	
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		Alpha.push_back(input);
	}

	

	for (int i = 0; i < Alpha.size(); i++)  // STore 배열에 모두  계수를 저장해주었다.
	{
		int Pow = 1;

		for (int j = Alpha[i].size() - 1; j >= 0; j--)
		{  
			int Num = (Alpha[i])[j] - 'A';
			cout << "/////////////" << Num << "/////////" << endl;
			STore[Num] += Pow;
			Pow *= 10;
		}
	}
	
	/*for (int i = 0; i < 26; i++)
		cout << STore[i] << " ";
	    cout << "\n";*/
	

	sort(STore, STore + 26);  //  소트 정렬을 해준다.

	/*for (int i = 0; i < 26; i++)
		cout << STore[i] << " ";
	cout << "\n";*/
	
	int answer = 0; int Num = 9;

	for (int i = 25; i >= 0; i--)
	{
		if (STore[i] == 0)
			break;
		answer += STore[i] * Num;
		Num--;
		
	}

	cout << answer;
	

	system("pause");
	return 0;
}