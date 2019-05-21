#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool DP[2500][2500] = { false, }; // 2500�ڸ����� �ִ��̹Ƿ�  0-2499���� �� ���̴�.
int DP_min[2500] = { 0 };

int main(void)
{
	//1. �Է��� �޴´�.
	string input;
	cin >> input;

	int N = input.size();  // ���ڿ��� ����

	//2.  DP �迭�� ä���.
	for (int i = 0; i < N; i++)  // ���� �� �ʱ�ȭ
	{
		DP[i][i] = true;

	}

	for (int i = 0; i < N-1; i++)  // ���ڸ����� �� �ʱ�ȭ
	{
		if (input[i] == input[i + 1])
			DP[i][i + 1] = true;
	}

	for (int i = 2; i <= N - 1; i++) // 3�ڸ��� �̻��� ��  
	{
		for (int j = 0; j < N - i; j++)
		{
			if ((input[j] == input[j + i]) && DP[j + 1][j + i - 1])
				DP[j][i] = true;

		}
	}


	//3. dp_min�� ä����
	DP_min[0] = 1;
	DP_min[1] = 1 + (input[0] != input[1]);

	if (DP[0][N - 1]) // ���� �ƿ� ó������ �Ӹ���� ���� ���
		DP_min[N - 1] = 1;

	for (int i = 2; i <= N - 1; i++)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			DP_min[i] = -1;

			if (DP[j][i])
			{
				if ((DP_min[i] == -1) || (DP_min[i] > DP_min[j - 1] + 1))
				{

					DP_min[i] = DP_min[j - 1] + 1;
				}
			}
		}

	}



	cout << DP_min[N];



	system("pause");
	return 0;
}