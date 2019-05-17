#include <iostream>
#include <algorithm>
using namespace std;

int house_cost[1001][3];
int result[1001][3];


int main(void)
{
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++)   // �Է�
	{
		int r, g, b;
		cin >> r >> g >> b;
		house_cost[i][0] = r;
		house_cost[i][1] = g;
		house_cost[i][2] = b;

	}


	// ���� ��� ���


	for (int i = 1; i <= N; i++)
	{
		result[i][0] = min(result[i - 1][1], result[i - 1][2]) + house_cost[i][0];
		result[i][1] = min(result[i - 1][0], result[i - 1][2]) + house_cost[i][1];
		result[i][2] = min(result[i - 1][0], result[i - 1][1]) + house_cost[i][2];
	}



	// ��� ��� : �ּڰ�

	int answer = min(min(result[N][0], result[N][1]), result[N][2]);
	

	cout << answer;

	system("pause");
	return 0;
}