#include <iostream>
#include <algorithm>
using namespace std;

int input[501][501] = { 0, };
int DP[501][501] = { 0, }; // DP배열은 0으로 초기화

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// input배열에 입력을 받자
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) { // 등호 주의
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

	// DP배열 초기화
	DP[0][0] = input[0][0];
	DP[1][0] = input[0][0] + input[1][0];
	DP[1][1] = input[0][0] + input[1][1];

	// DP배열을 반복문을 돌면서 밑에서부터 채워나감
	// 점화식 : D[i][j] = max(D[i-1][j-1], D[i-1][j]) + input[i][j]
	// 단 j = 0일때는 D[i-1][j-1] 계산 안함, j = n일 때는 D[i-1][j] 계산 안함

	int answer = 0;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= i; j++) {	// 등호 주의
			if (j == 0) {
				DP[i][j] = DP[i - 1][j] + input[i][j];
			}
			else if (j == i) {
				DP[i][j] = DP[i - 1][j - 1] + input[i][j];
			}
			else {
				DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + input[i][j];
			}

			// 만약 i == n-1일때, 그 경우 최댓값을 계산함
			if (i == n-1 && answer < DP[i][j]) {
				answer = DP[i][j];
			}
		}
	}

	cout << answer;
	return 0;
}