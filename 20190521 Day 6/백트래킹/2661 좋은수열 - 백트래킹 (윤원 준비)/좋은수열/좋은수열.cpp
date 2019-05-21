#include <iostream>
#include <string>
using namespace std;

// 좋은수열
// N : 1일 경우  1
// N : 2일 경우  12
// N : 3일 경우  121
// N : 4일 경우  1213
// N : 5일 경우  12131
// N : 6일 경우  121312
// N : 7일 경우  1213121
// N : 8일 경우  1213123 1
// N : 9일 경우  1213123 12
// N : 10일 경우 1213123 121
// N : 11일 경우 1213123 1213
// N : 12일 경우 1213123 12131
// N : 13일 경우 1213123 121312
// N : 14일 경우 1213123 1213231
// N : 15일 경우 1213123 1213231 2
// ...


/*
string의 substr 함수를 잘 이용해야하는 백트래킹 문제

1. 1, 2, 3으로만 이루어지므로 반복문을 통해 1, 2, 3을 더해나간다.
2. 조건이 최초로 만족할 경우가 제일 작은 숫자이므로 출력하고 프로그램 종료
3. substr을 이용하여 인접한 부분 문자열이 같은지 확인
*/
int N;
string num;

void recursion(char c, int cnt) {
	// 조건을 만족하는 경우 (제일 먼저 나오는 숫자가 제일 작은 수이다.)
	if (cnt - 1 == N) {
		cout << num << "\n";
		exit(0);
	}

	num += c;
	for (int i = 1; i <= cnt / 2; i++) {
		string a = num.substr(cnt - i, i);
		string b = num.substr(cnt - i * 2, i);

		// 나쁜 수열
		if (a == b) {
			num.erase(cnt - 1);
			return;
		}
	}

	for (int i = 1; i <= 3; i++) {
		recursion(i + '0', cnt + 1);
	}
	num.erase(cnt - 1); // cnt - 1 자리가 성립하지 않을 경우
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= 3; i++)
		recursion(i + '0', 1);

	return 0;
}