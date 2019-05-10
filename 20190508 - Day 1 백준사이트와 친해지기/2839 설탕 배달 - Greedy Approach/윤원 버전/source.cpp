#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력을 받는다.
	int N;
	cin >> N;
	
	int five, three;
	// 만약 5의 배수이면 바로 출력
	if (N % 5 == 0) {
		cout << N / 5;
		return 0;
	}
	else if (N % 3 == 0) {
		// 만약 3의 배수이면 바로 출력
		cout << N / 3;
		return 0;
	}
	
	// 일단 가장 큰 걸로 최대한 담는다.


	// 그걸로 안 되면, 가장 큰 걸 하나씩 빼보자


	// 조건에 맞으면 출력하고 종료


	// 하나도 안 될 경우 -1 출력



	return 0;
}