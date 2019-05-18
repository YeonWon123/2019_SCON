#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int chk[2500][2500];
char input[2501];	// '\0' 문자 조심!
int dp[2500] = { 0, };
int chk_1(int i, int j);

int main(void)
{
	cin >> input;
	int length = strlen(input);
	//	for (int i = 0; i < length; i++)
	//		cout << input[i];
	//	cout << "\n";

		// 길이가 1인 문자열은 무조건 팰린드롬
		// 대각선 방향으로, 일단 1로 초기화
	for (int i = 0; i < length; i++) {
		chk[i][i] = 1;
		//		printf("chk[%d][%d] = %d\n", i, i, chk[i][i]);
	}


	// 길이가 2인 문자열이 팰린드롬인지 살펴보자
	// chk[i][j]에서 -> input[i] = input[j]이면 1, 아니면 0으로 두자.
	for (int i = 0; i < length - 1; i++) {
		if (input[i] == input[i + 1])
			chk[i][i + 1] = 1;
		else
			chk[i][i + 1] = 0;
		//	printf("chk[%d][%d] = %d\n", i, i+1, chk[i][i + 1]);
	}

	// 이제, 양 끝단의 문자가 같으면, 그 안의 문자열이 팰린드롬인지 알아보면 된다!
	for (int j = 2; j < length; j++) {
		for (int i = 0; i < length - j; i++) {
			//	printf("input[%d]: %c, input[%d]: %c\n", i, input[i], i + j, input[i + j]);
			if (input[i] == input[i + j]) {
				//		printf("같음!\n");
				chk[i][i + j] = chk[i + 1][i + j - 1];
				//		printf("chk[%d][%d] = %d\n", i + 1, i + j - 1, chk[i+1][i + j - 1]);
			}
			else {
				chk[i][i + j] = 0;
			}
			//	printf("chk[%d][%d] = %d\n", i, i + j, chk[i][i + j]);
		}
	}

	// 이제 팰린드롬 분할의 개수의 최솟값을 알아보자.

	dp[0] = 1;
//	dp[1] = min(dp[0] + chk[1][1], chk_1(0, 1));
//	dp[2] = min(dp[1] + chk[2][2], dp[0] + chk_1(1, 2), chk_1(0, 2));
//	dp[3] = min(dp[2] + chk[3][3], dp[1] + chk_1(2, 3), dp[0] + chk_1(1, 3), chk_1(0, 3));
	int min_value = 999999;
	for (int i = 1; i < length; i++) { // j -> 1 to j <= i;
		int temp1, temp2;
	//	cout << "dp[" << i - 1 << "] + chk[" << i << "][" << i << "] = " << dp[i - 1] + chk[i][i] << endl;
		temp1 = dp[i - 1] + chk[i][i];
		for (int j = 1; j <= i; j++) {
	//		cout << "chk[" << i - j << "]["<< i << "]=" << chk[i - j][i] << endl;
			if (chk[i - j][i] == 1) {
	//			cout << "dp[" << i - j << "] + chk_1(" << i-j << ", " << i << ") = " << dp[i - j] + chk_1(i-j, i) << endl;
				temp2 = dp[i - j - 1] + chk_1(i - j, i);
				if (temp1 > temp2) temp1 = temp2;
			}
				//		dp[i] = min(dp[i - 1(j)] + chk[i][i], dp[i - 2(j+1)] + chk_1(i - 1(j), i));
				//		dp[i] = min(dp[i - 1(j)] + chk[i][i], dp[i - 2(j+1)] + chk_1(i - 1(j), i), chk(i - 2(j+1), i));
				//		dp[i] = min(dp[i - 1(j)] + chk[i][i], dp[i - 2(j+1)] + chk_1(i - 1(j), i), dp[i - 3(j+2)] + chk_1(i - 2(j+1), i), chk_1(i - 3(j+2), i));
		}
		if (temp1 > chk_1(0, i)) temp1 = chk_1(0, i);
		dp[i] = temp1;
	}

//	for (int i = 1; i < length; i++) {
//		dp[i] = min(dp[i - 1] + chk[i][i], dp[i - 2] + chk_1(i - 1, i));
//		dp[i] = min(dp[i - 1] + chk[i][i], dp[i - 2] + chk_1(i - 1, i), chk(i - 2, i));
//		dp[i] = min(dp[i - 1] + chk[i][i], dp[i - 2] + chk_1(i - 1, i), dp[i - 3] + chk_1(i - 2, i), chk_1(i - 3, i));
//	}

//	for (int i = 0; i < length; i++)
//		cout << dp[i] << " ";

	cout << dp[length - 1];
	return 0;
}

int chk_1(int i, int j)
{
	if (chk[i][j] == 1)
		return 1;
	else
		return j - i + 1;
}