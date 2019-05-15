#include <iostream>
using namespace std;

int coin[10002]; // 코인들을 저장하는 배열
int DP[10002];  // DP[1]  은 주어진 코인들로 1의 가치를 만드는 경우
                // DP[2]  은 주어진 코인들로 2의 가치를 만드는 경우  .....


int main(void)
{
	int n, k;  // n가지 종류의 동전 , 가치의 합이 k원인 경우

	cin >> n, k;

	for (int i = 0; i < n; i++) // coin 입력
		cin >> coin[i];



	DP[0] = 1; // 아무 코인도 선택하지 않는 경우 한가지이다.

	for (int i = 0; i < n; i++) //코인 제어 
	{

		for (int j = 1; j <= k; j++)  //dp 제어
		{
			if (j - coin[i] >= 0)
				DP[j] = DP[j] + DP[j - coin[i]];   // ????????
		}

	}

	cout << DP[k];


	system("pause");
	return 0;
}