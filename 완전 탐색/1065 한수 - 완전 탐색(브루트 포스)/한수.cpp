#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	// 입력으로 일의 자리 숫자 또는 십의 자리 숫자가 들어온다면
	if (N < 100) {
		cout << N;
		return 0;
	}
	else if (N == 1000) { // 입력으로 1000이 들어온다면 (특수한 경우)
		cout << 144;	// 예제에 나온것처럼 144 출력
		return 0;
	}
	else { // 입력으로 백의 자리 수가 들어온다면
		// 자릿수를 뽑아보자.
		int pos[3];
		int counts = 0;
		// pos[0]에는 백의 자리 숫자가, pos[1]에는 십의 자리 숫자가, pos[2]에는 일의 자리 숫자가
		// 들어갈 수 있게 해보자
		// 나눗셈 연산 (/) or 나머지 연산 (%) 을 이용할 수도 있다.
		for (int i = 100; i <= N; i++) {
			// 123일 경우
			pos[0] = i / 100;						    // 1 = 123/100
			pos[1] = (i - 100 * pos[0]) / 10;		    // 2 = (123 - 100 * 1) / 10
			pos[2] = (i - 100 * pos[0] - 10 * pos[1]);	// 3 = (123 - 100 * 1 - 10 * 2)

			if ((pos[0] - pos[1]) == (pos[1] - pos[2])) {
				counts++;
			}
		}

		cout << counts + 99;
		return 0;
	}
	
	return 0;
}