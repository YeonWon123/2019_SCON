// 2-D array DP 풀이
/*
1. 재귀함수를 통해 갈 수 있는 방법에 대해 계속 탐색한다.
2. 계산한 내용을 DP 배열에 저장해 놓는다.
3. DP에 저장된 값이 있다면 DP값을 리턴한다.
*/

#include <iostream>
using namespace std;

int n, k, endpoint;
int delay_time[1001];
int rule[1001][1001];
int dp[1001];

int Max(int a, int b) {
	return a > b ? a : b;
}

int cal(int a) {
	if (dp[a] != 0) {
		return dp[a];
	}
	else {
		int result = 0;
		for (int i = 1; i <= n; i++) {
			if (rule[a][i] == 1) {
				result = Max(result, cal(i));
			}
		}
		return dp[a] = result + delay_time[a];
	}
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			delay_time[i] = 0;
			dp[i] = 0;
			for (int j = 1; j <= n; j++) {
				rule[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			cin >> delay_time[i];
		}
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			rule[b][a] = 1;
		}
		cin >> endpoint;
		cout << cal(endpoint) << '\n';
	}
	return 0;
}
Colored by Color Scripter
