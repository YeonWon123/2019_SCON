#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int pos[7];  // 각 자리수에 해당하는 숫자
	cin >> N;

	// 입력값으로 N이 주어지면 1부터 N까지 다 해본다. 단 어차피 N은 안되니 N-1까지만 해봐도 된다.
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

	cout << 0; // 1부터 N까지 다 해봐도 생성자가 없는 경우
	return 0;
}