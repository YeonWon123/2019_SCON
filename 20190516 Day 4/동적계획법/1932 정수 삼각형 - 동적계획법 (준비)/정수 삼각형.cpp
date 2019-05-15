#include <iostream>
#include <algorithm>
using namespace std;

int input[501][501] = { 0, };
int DP[501][501] = { 0, }; // DP�迭�� 0���� �ʱ�ȭ

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// input�迭�� �Է��� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) { // ��ȣ ����
			cin >> input[i][j];
		}
	}

	if (n == 1) {
		cout << input[0][0];
		return 0;
	}

	if (n == 2) {
		cout << max(input[0][0] + input[1][0], input[0][0] + input[1][1]);
		return 0;
	}

	// DP�迭 �ʱ�ȭ
	DP[0][0] = input[0][0];
	DP[1][0] = input[0][0] + input[1][0];
	DP[1][1] = input[0][0] + input[1][1];

	// DP�迭�� �ݺ����� ���鼭 �ؿ������� ä������
	// ��ȭ�� : D[i][j] = max(D[i-1][j-1], D[i-1][j]) + input[i][j]
	// �� j = 0�϶��� D[i-1][j-1] ��� ����, j = n�� ���� D[i-1][j] ��� ����

	int answer = 0;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= i; j++) {	// ��ȣ ����
			if (j == 0) {
				DP[i][j] = DP[i - 1][j] + input[i][j];
			}
			else if (j == i) {
				DP[i][j] = DP[i - 1][j - 1] + input[i][j];
			}
			else {
				DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + input[i][j];
			}

			// ���� i == n-1�϶�, �� ��� �ִ��� �����
			if (i == n-1 && answer < DP[i][j]) {
				answer = DP[i][j];
			}
		}
	}

	cout << answer;
	return 0;
}