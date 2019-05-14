#include <iostream>
#include <cmath>
using namespace std;

// 전역변수
int N, r, c;
int answer = 0;
bool findanswer = false;

// 방향을 나타내는 배열
int ny[4] = {0, 0, 1, 0};
int nx[4] = {0, 1, -1, 1};

// 재귀함수
void search(int y, int x, int length);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> r >> c;
	search(0, 0, pow(2, N));
	return 0;
}

void search(int y, int x, int length) {
	// 답을 찾았을 경우 재귀함수를 모두 종료하게 함
	if (findanswer == true)
		return;

	int py = y;
	int px = x;

	// length가 2일 경우 방문 시작
	if (length == 2) {
		for (int i = 0; i < 4; i++) {
			py = py + ny[i];
			px = px + nx[i];

		//	cout << py << " " << px << "\n";
			if (py == r && px == c) {
				cout << answer;
				findanswer = true;
				return;
			}
			answer++;
		}
		return;
	}
	else {	// length가 2가 아닐 경우
		// 재귀호출
		search(y, x, length / 2);
		search(y, x + length / 2, length / 2);
		search(y + length / 2, x, length / 2);
		search(y + length / 2, x + length / 2, length / 2);
	}
}