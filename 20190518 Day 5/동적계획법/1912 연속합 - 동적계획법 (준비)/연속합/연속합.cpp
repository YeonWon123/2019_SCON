#include <iostream>
#include <algorithm>
using namespace std;

int input[100001] = { 0, };
int sum = 0;
int answer = 0;
// 10 -4 3 1 5 6 -35 12 21 -1
// ������ ������ ����?

// 10 6 9 10 15 21 -35
// max = ����! ����!

// 12 21 -1
// max = �����������̷��� �ɵ�

// ��, ���� 0 �Ǵ� ������ �־��� ���� ����
// �׷��� �� ���� ����ó���� ������

int main(void)
{
	// �Է¹ޱ�
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int plus_flag = 0;
	int max_number;

	for (int i = 0; i < n; i++) {
		cin >> input[i];

		if (i == 0)
			max_number = input[i];
		else {
			max_number = max(max_number, input[i]);
		}

		if (input[i] > 0) {
			plus_flag = 1;
		}
	}

	// 0�� ������ ���� ��� ���� ū ���� ����
	if (plus_flag == 0) {
		cout << max_number;
		return 0;
	}

	// ����� �ִٸ�, DP �̿��Ͽ� �ִ��� �κ��� ���ϱ�
	// input �迭�� �ؿ������� ��ȸ�Ͽ� answer�� ã��.
	for (int i = 0; i < n; i++) {
		sum += input[i];
		if (sum < 0) { // �����̸�
			sum = 0;   // sum = 0���� �ΰ� �� �������� start
		}

		if (answer < sum) {
			answer = sum;
		}
	}

	cout << answer;
	return 0;
}