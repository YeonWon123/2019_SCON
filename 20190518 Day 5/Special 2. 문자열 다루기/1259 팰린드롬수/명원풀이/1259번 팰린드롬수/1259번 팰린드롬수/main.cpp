#include <iostream>
#include <string>
#include <cstring>
#include<vector>

using namespace std;

vector<int> input;  // input을 받아서 벡터에  집어 넣어준다
bool number[5][5] = { false, }; // 자릿수를 쪼개서 배열에 넣어준다.
string inputarr;  // 벡터에 있는 요소를 string에 넣어 주낟.
int N; // 자릿 수

int num(int j);  // 자릿수 구하는 함수   
void DPmake(int j);

int main(void)
{
	// 1. 입력을 넣어준다. (입력의 끝에는 0이 나온다.) 입력 N개

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int a = 1;
	//int count = 0;
	
	while (a != 0)
	{
		cin >> a;

		DPmake(a); //  DP 배열을 채워준다.

		if (a == 0)
			break;

		if (number[0][N - 1])
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";

		memset(number, false, sizeof(number));  // 초기화를 한번 해준다.
	}


	// 2. DP 배열을 채워준다.

	 // DPmake 함수를 통해 만든다.


	//system("pause");
			return 0;
}

int num(int j)
{   

	string str = to_string(j);
	inputarr = str;
	N = inputarr.size();  // 요소의 길이
	return N;
}

void DPmake(int j)
{
	  // 벡터의 주소
	for (int i = 0; i < num(j); i++)  // i부터 i 일때는 초기화를 해준다.
	{
		number[i][i] = true;
	}

	for (int i = 0; i < num(j); i++) // 두자릿수 일때는  같으면 true
	{
		if (inputarr[i] == inputarr[i + 1])
			number[i][i + 1] = true;
	}

	//  나머지는 채워준다.  

	for (int i = 2; i <= N - 1; i++)
	{
		for (int j = 0; j < N - i; j++)
		{
			if (inputarr[j] == inputarr[i + j] && number[j + 1][j + i - 1])
				number[j][i + j] = true;
		}

	}
}