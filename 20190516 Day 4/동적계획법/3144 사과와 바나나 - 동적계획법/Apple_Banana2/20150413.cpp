#include <iostream>
#include <algorithm>
using namespace std;

//#define DEBUG

char in_c[1501][1501]; // A 혹은 B 입력
int in_num[1501][1501];  // 개수 입력
int max_sum_a[1501][1501];	// 사과의 부분합 (맨 끝에서부터 인덱스가 1인 쪽으로 더함)
int max_sum_b[1501][1501];	// 바나나의 부분합 (맨 끝에서부터 인덱스가 1인 쪽으로 더함)
int dp[1501][1501];

int main(void)
{
	// 입력받기
	int R, C;
	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> in_c[i][j];
			cin >> in_num[i][j];
		}
	}

	// 행별로 사과의 부분합 구하기, 단, 끝에서 1로 가야 한다.
	for (int i = 1; i <= R; i++) {
		for (int j = C; j > 0; j--) {
			if (in_c[i][j] == 'A') {
				if (j == C)	max_sum_a[i][j] = in_num[i][j];
				else max_sum_a[i][j] = max_sum_a[i][j + 1] + in_num[i][j];
			}
			else {
				if (j == C) max_sum_a[i][j] = 0;
				else max_sum_a[i][j] = max_sum_a[i][j + 1];
			}
		}
	}
	
	// 열별로 바나나의 부분합 구하기, 단, 끝에서 1로 가야 한다.
	for (int j = 1; j <= C; j++) {
		for (int i = R; i > 0; i--) {
			if (in_c[i][j] == 'B') {
				if (i == R)	max_sum_b[i][j] = in_num[i][j];
				else max_sum_b[i][j] = max_sum_b[i+1][j] + in_num[i][j];
			}
			else {
				if (i == R) max_sum_b[i][j] = 0;
				else max_sum_b[i][j] = max_sum_b[i+1][j];
			}
		}
	}

#ifdef DEBUG

	cout << "\n\nmax_sum_a\n";
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << max_sum_a[i][j] << " ";
		}
		cout << "\n";
	}


	cout << "\n\nmax_sum_b\n";
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << max_sum_b[i][j] << " ";
		}
		cout << "\n";
	}

#endif

	// dp 배열 초기화
	for (int i = 0; i <= R; i++) {
		for (int j = 0; j <= C; j++) {
			dp[i][j] = 0;
		}
	}
	
	// dp[i][j] : (1,1)부터 (i,j)까지 불도저가 이동할 때,
	//			  사과와 바나나를 더한 최대 값
	
	// dp[i][j]의 경우는, 다음 3가지 경우가 있다.
	// 불도저가 위에서 내려오는 경우, 왼쪽에서 오는 경우, 대각선으로 오는 경우
	// 이 세 경우 중 사과와 바나나의 합이 더 크게 되는 값을 취한다.
	// i나 j 중 한 곳이라도 1일 경우 사과와 바나나는 존재할 수 없다. (불도저가 다 밀 수 있기 때문)
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (i == 1 || j == 1) {
				dp[i][j] = 0;
			}
			else {
				// 일반적인 경우 계산
				// dp[i][j] = max( "대각선", max("왼쪽->오른쪽", "위쪽->아래쪽") );
				dp[i][j] = max(dp[i - 1][j - 1] + max_sum_a[i][1] - max_sum_a[i][j] + max_sum_b[1][j] - max_sum_b[i][j],
					max(dp[i][j - 1] + max_sum_b[1][j] - max_sum_b[i][j], dp[i - 1][j] + max_sum_a[i][1] - max_sum_a[i][j]) );
			}
		}
	}
	
	/*
	// 왼쪽 -> 오른쪽
	dp[i][j] = dp[i][j - 1] + max_sum_b[1][j] - max_sum_b[i][j];
	// 위쪽 -> 아래쪽
	dp[i][j] = dp[i - 1][j] + max_sum_a[i][1] - max_sum_a[i][j];
	// 대각선
	dp[i][j] = dp[i-1][j-1] + max_sum_a[i][1] - max_sum_a[i][j] + max_sum_b[1][j] - max_sum_b[i][j]
	*/

#ifdef DEBUG
	cout << "\n\ndp\n";
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

#endif
	/*
	// 불도저가 위에서 내려오는 경우, 사과에 영향을 준다. 따라서 그 줄 사과를 구한다.
	dp[i][j] = dp[i][j - 1] - max_sum_a[i][j];

	// 불도저가 왼쪽에서 오는 경우, 바나나에 영향을 준다. 따라서 그 줄 바나나를 구한다.
	dp[i][j] = dp[i - 1][j] - max_sum_b[i][j];

	// 불도저가 대각선으로 오는 경우, 사과와 바나나 모두에 영향을 주므로, 그 둘을 모두 구한다.
	dp[i][j] = dp[i - 1][j - 1] - max_sum_a[i][j] - max_sum_b[i][j];
	*/
	// 오른쪽으로 가는 경우
	// 다음 칸의 열에 해당하는 바나나의 부분합을 더한다. 
	
	
	// 대각선으로 가는 경우
	// 다음 칸의 행, 열에 해당하는 사과와 바나나의 부분합을 더한다.
	
	
	// 아래로 가는 경우
	// 다음 칸의 행에 해당하는 사과의 부분합을 더한다.

	// 답안 출력
	cout << dp[R][C];
	return 0;
}