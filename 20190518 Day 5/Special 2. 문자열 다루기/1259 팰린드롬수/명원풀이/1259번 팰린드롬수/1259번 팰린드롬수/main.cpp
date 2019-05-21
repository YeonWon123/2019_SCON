#include <iostream>
#include <string>
#include <cstring>
#include<vector>

using namespace std;

vector<int> input;  // input�� �޾Ƽ� ���Ϳ�  ���� �־��ش�
bool number[5][5] = { false, }; // �ڸ����� �ɰ��� �迭�� �־��ش�.
string inputarr;  // ���Ϳ� �ִ� ��Ҹ� string�� �־� �ֳ�.
int N; // �ڸ� ��

int num(int j);  // �ڸ��� ���ϴ� �Լ�   
void DPmake(int j);

int main(void)
{
	// 1. �Է��� �־��ش�. (�Է��� ������ 0�� ���´�.) �Է� N��

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int a = 1;
	//int count = 0;
	
	while (a != 0)
	{
		cin >> a;

		DPmake(a); //  DP �迭�� ä���ش�.

		if (a == 0)
			break;

		if (number[0][N - 1])
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";

		memset(number, false, sizeof(number));  // �ʱ�ȭ�� �ѹ� ���ش�.
	}


	// 2. DP �迭�� ä���ش�.

	 // DPmake �Լ��� ���� �����.


	//system("pause");
			return 0;
}

int num(int j)
{   

	string str = to_string(j);
	inputarr = str;
	N = inputarr.size();  // ����� ����
	return N;
}

void DPmake(int j)
{
	  // ������ �ּ�
	for (int i = 0; i < num(j); i++)  // i���� i �϶��� �ʱ�ȭ�� ���ش�.
	{
		number[i][i] = true;
	}

	for (int i = 0; i < num(j); i++) // ���ڸ��� �϶���  ������ true
	{
		if (inputarr[i] == inputarr[i + 1])
			number[i][i + 1] = true;
	}

	//  �������� ä���ش�.  

	for (int i = 2; i <= N - 1; i++)
	{
		for (int j = 0; j < N - i; j++)
		{
			if (inputarr[j] == inputarr[i + j] && number[j + 1][j + i - 1])
				number[j][i + j] = true;
		}

	}
}