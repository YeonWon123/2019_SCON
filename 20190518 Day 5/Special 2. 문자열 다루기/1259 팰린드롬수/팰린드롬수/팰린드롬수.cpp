#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
//#define DEBUG
using namespace std;

int dp[5][5] = { 0, };
int input_number[5];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input = -1;
	int length;
	while (1) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				dp[i][j] = 0;
			}
		}

		cin >> input;
		if (input == 0) return 0;

		else {
			// 몇 자리 숫자인지 확인
			if (input / 10000 != 0)
				length = 5;
			else if (input / 1000 != 0)
				length = 4;
			else if (input / 100 != 0)
				length = 3;
			else if (input / 10 != 0)
				length = 2;
			else
				length = 1;

			if (length == 1) {
				cout << "yes\n";
				continue;
			}
			else {
				for (int i = 0; i <= length - 1; i++) {
					int ndiv = pow(10, length - 1 - i);
					input_number[i] = input / ndiv;
					input = input % ndiv;
				}
			}
#ifdef DEBUG
			cout << length << "\n";
			for (int i = 0; i < length; i++) {
				cout << input_number[i];
			}
			cout << "\n";
#endif
			// DP 배열 채우기
			for (int i = 0; i < length; i++) {
				dp[i][i] = 1;
			}

			for (int i = 0; i < length - 1; i++) {
				if (input_number[i] == input_number[i + 1])
					dp[i][i + 1] = 1;
			}

			for (int i = 2; i < length; i++) {
				for (int j = 0; j < length - i; j++) {
					if (dp[j + 1][j + i - 1] && input_number[j] == input_number[j + i])
						dp[j][j + i] = 1;
				}
			}
#ifdef DEBUG
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					cout << dp[i][j] << " ";
				}
				cout << "\n";
			}
#endif
			if (dp[0][length - 1] == 1)
				cout << "yes\n";
			else
				cout << "no\n";
		}
	}
	return 0;
}