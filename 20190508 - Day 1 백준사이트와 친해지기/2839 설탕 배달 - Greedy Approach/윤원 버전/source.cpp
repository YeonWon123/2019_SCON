#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	// �Է��� �޴´�.
	int N;
	cin >> N;
	
	int five, three;
	// ���� 5�� ����̸� �ٷ� ���
	if (N % 5 == 0) {
		cout << N / 5;
		return 0;
	}
	else if (N % 3 == 0) {
		// ���� 3�� ����̸� �ٷ� ���
		cout << N / 3;
		return 0;
	}
	
	// �ϴ� ���� ū �ɷ� �ִ��� ��´�.


	// �װɷ� �� �Ǹ�, ���� ū �� �ϳ��� ������


	// ���ǿ� ������ ����ϰ� ����


	// �ϳ��� �� �� ��� -1 ���



	return 0;
}