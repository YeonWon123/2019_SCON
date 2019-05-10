#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int pos[7];  // �� �ڸ����� �ش��ϴ� ����
	cin >> N;

	// �Է°����� N�� �־����� 1���� N���� �� �غ���. �� ������ N�� �ȵǴ� N-1������ �غ��� �ȴ�.
	for (int i = 1; i < N; i++) {
		int temp = i;
		int pos_sum = 0;

		for (int j = 6; j >= 0; j--) {
			pos[j] = temp / pow(10, j);
			temp = temp - pow(10, j) * pos[j];
			pos_sum = pos_sum + pos[j];
		}

		if (N == i + pos_sum) {
			cout << i;
			return 0;
		}
	}

	cout << 0; // 1���� N���� �� �غ��� �����ڰ� ���� ���
	return 0;
}