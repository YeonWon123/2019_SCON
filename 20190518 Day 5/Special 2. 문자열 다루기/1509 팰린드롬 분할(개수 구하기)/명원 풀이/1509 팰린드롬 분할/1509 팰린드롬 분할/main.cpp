#include <iostream>
#include <string>
#include <algorithm>
//#define DEBUG
using namespace std;

bool DP[2500][2500] = { false, }; // 2500자릿수가 최대이므로  0-2499까지 쓸 것이다.
int DP_min[2500];

int main(void)
{
	//1. 입력을 받는다.
	string input;
	cin >> input;

	int N = input.size();  // 문자열의 길이

	//2.  DP 배열을 채운다.
	for (int i = 0; i < N; i++)  // 같을 때 초기화
	{
		DP[i][i] = true;

	}

	for (int i = 0; i < N-1; i++)  // 두자릿수일 때 초기화
	{
		if (input[i] == input[i + 1])
			DP[i][i + 1] = true;
	}

	for (int i = 2; i <= N - 1; i++) // 3자릿수 이상일 때  
	{
		for (int j = 0; j < N - i; j++)
		{
			if ((input[j] == input[j + i]) && DP[j + 1][j + i - 1])
				DP[j][i+j] = true;

		}
	}

#ifdef DEBUG
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << DP[i][j] << " ";
		}
		cout << "\n";
	}
#endif
	
	for (int a = 2; a < N; a++)
	{
		DP_min[a] = 99999;
	}


	//3. dp_min을 채우자
	DP_min[0] = 1;
	DP_min[1] = 1 + (input[0] != input[1]);

	if (DP[0][N - 1]) // 만일 아예 처음부터 팰린드롬 수일 경우
	{
		cout << 1;
		return 0;
	}
		
	
	

	for (int i = 2; i <= N - 1; i++)
	{
		if (DP[0][i]) // 만일 아예 처음부터 팰린드롬 수일 경우
		{
			DP_min[i] = 1;
			continue;
		}

		for (int j = i; j >= 1; j--)
		{
			

			if (DP[j][i])
			{
				if ( (DP_min[i] > DP_min[j - 1] + 1))
				{

					DP_min[i] = DP_min[j - 1] + 1;
#ifdef DEBUG
					cout << i << "일때 DP_min " << DP_min[i] << "\n";
#endif
				}
			}
			else
			{
				if (DP_min[i] > DP_min[j - 1] + i - j + 1) 
				{
					DP_min[i] = DP_min[j - 1] + i - j + 1;
					//cout << i << "일때 DP_min " << DP_min[i] << "\n";
				}
			}
			
		}

	}
#ifdef DEBUG
	for (int i = 0; i < N; i++) {
		cout << DP_min[i] << " ";
	}
#endif
	cout << DP_min[N-1];



	system("pause");
	return 0;
}