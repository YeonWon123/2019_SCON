#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);


	int a[9] = { 0 };
	int sum = 0;
	int sub = 0, i_index = 0, j_index = 0;

	for (int i = 0; i <9; i++)  // 9�������� Ű�� �Է����ش�.
	{                             // ��� ���� ���Ѵ�.
		cin >> a[i];
		sum += a[i];
	}

	sub = sum - 100;

	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sub == a[i] + a[j])
			{
				i_index = i;
				j_index = j;

			}
		}
	}

	a[i_index] = 0;
	a[j_index] = 0;

	sort(a, a + 9);    // stl�� �̿��Ͽ�  ������������ �������ش�.

	for (int i = 2; i < 9; i++) // �Ǿ� 0�ΰ��� ���� ����� ���ش�.
		cout << a[i] << "\n";

	//system("pause");
	return 0;
}