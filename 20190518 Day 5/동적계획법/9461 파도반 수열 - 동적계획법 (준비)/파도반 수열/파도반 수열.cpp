#include <iostream>
using namespace std;

// 파도반 수열
// 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, ...
// 규칙은? 1, 1, 1, 2, 2, (2+1), (3+1), (4+1), (5+2), (7+2), (9+3), (12+4), (16+5), ...
// 따라서, dp[101]을 잡고, index는 1부터 100까지만 쓰자.
// 점화식은 다음과 같다.
// P[i] = P[i-1] + P[i-5] (단, i > 5)
// P[i] = 1 (i == 1, 2, 3)
// P[i] = 2 (i == 4, 5)

// 파도반 수열을 저장하는 배열로, DP방법으로 밑에서부터 채워나감
// overflow에 주의!!! int로 하면 오류남!!!
// long long으로 안전하게 한다. 주의주의!
// 무조건 제일 큰 값을 테스트해본 뒤 올릴것
long long P[101] = { 0, };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 파도반 수열 채워나가기 (100까지이니 일단 100까지 다 채우기)
	// index는 1부터 100까지
	for (int i = 1; i <= 100; i++) {
		if (i <= 3) {
			P[i] = 1;
		}
		else if (i <= 5) {
			P[i] = 2;
		}
		else {
			P[i] = P[i - 1] + P[i - 5];
		}
	}
	

	// 입력 받기
	int T;
	cin >> T;

	int N;
	// 각각의 test case에 대하여 N이 주어지면, P(N)을 출력
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << P[N] << "\n";
	}
		
	return 0;
}