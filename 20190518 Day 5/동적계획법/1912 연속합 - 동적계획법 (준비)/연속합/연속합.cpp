#include <iostream>
#include <algorithm>
using namespace std;

int input[100001] = { 0, };
int sum = 0;
int answer = 0;
// 10 -4 3 1 5 6 -35 12 21 -1
// 음수가 나오면 제외?

// 10 6 9 10 15 21 -35
// max = 음수! 제외!

// 12 21 -1
// max = ㅇㅇㅇㅇㅇ이러면 될듯

// 단, 수가 0 또는 음수만 주어질 수도 있음
// 그러면 이 경우는 예외처리를 해주자

int main(void)
{
	// 입력받기
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

	// 0과 음수만 있을 경우 가장 큰 값을 리턴
	if (plus_flag == 0) {
		cout << max_number;
		return 0;
	}

	// 양수가 있다면, DP 이용하여 최대의 부분합 구하기
	// input 배열을 밑에서부터 순회하여 answer를 찾자.
	for (int i = 0; i < n; i++) {
		sum += input[i];
		if (sum < 0) { // 음수이면
			sum = 0;   // sum = 0으로 두고 새 구간부터 start
		}

		if (answer < sum) {
			answer = sum;
		}
	}

	cout << answer;
	return 0;
}