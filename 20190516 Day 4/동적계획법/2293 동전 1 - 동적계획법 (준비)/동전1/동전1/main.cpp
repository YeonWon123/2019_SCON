#include <iostream>
using namespace std;

int coin[102]; // ���ε��� �����ϴ� �迭
int DP[10002] = { 0 };  // DP[1]  �� �־��� ���ε�� 1�� ��ġ�� ����� ���
                // DP[2]  �� �־��� ���ε�� 2�� ��ġ�� ����� ���  .....


int main(void)
{
	int n, k;  // n���� ������ ���� , ��ġ�� ���� k���� ���

	cin >> n, k;

	for (int i = 0; i < n; i++) // coin �Է�
		cin >> coin[i];


	// �ʱ�ȭ

	DP[0] = 1; // 0���� ���� �� �ִ� ��� �Ѱ����̴�.

	for (int i = 0; i < n; i++) //���� ���� 
	{

		for (int j = 1; j <= k; j++)  //dp ����
		{
			if (j - coin[i] >= 0)
				DP[j] = DP[j] + DP[j - coin[i]];   // ????????
		}

	}

	cout << DP[k];


	system("pause");
	return 0;
}