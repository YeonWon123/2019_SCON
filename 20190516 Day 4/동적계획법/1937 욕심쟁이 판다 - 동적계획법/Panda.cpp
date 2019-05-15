#include <iostream>
#include <algorithm>
using namespace std;

// 대나무 숲의 크기
int n;

// 대나무 숲의 정보
int input[501][501];

// dp와 메모리제이션을 하기 위한 기본 틀
int dp[501][501];

// N * N 크기의 대나무 숲은 이차원 배열로 취급.
// 여기서 특정 시작 위치가 있고 다음 위치는 현재보다 큰 값을 가지고 있어야 한다는 조건.
// 그래서 어디까지 이동할 수 있는지 저장할 수 있는 것이 필요.(memorization)
// 대나무 숲인 이차원 배열과 동일한 크기의 저장 공간이 있어야 한다.

// 대나무숲 N * N, 생존일 N * N
// 시작 위치가 대나무숲(a, b) 일 때의 생존 기간을 생존일(a, b)에 저장.

// A.	대나무숲(a, b)에서 시작
// B.	시작점 기준 상, 하, 좌, 우를 비교해 조건에 맞는 경우 이동.
// C.	B를 반복.생존일 누적.
// D.	B, C가 끝나면 누적된 생존일을 생존일(a, b)에 저장

int panda(int y, int x)
{
	// 만약 이전에 방문한 지점일 경우 그 지점의 값을 리턴
	if (dp[y][x])
		return dp[y][x];

	// 그렇지 않을 경우 기본값 1을 부여(무조건 하루는 살 수 있음)
	dp[y][x] = 1;

	// 대나무숲에서 시작 (y, x)
	// 시작점(y, x) 기준 상(y-1, x), 하(y+1, x), 좌(y, x-1), 우(y, x+1)를 비교해
	// 조건에 맞는 경우 재귀호출, but 그 값이 기존 dp[y][x]값보다 큰지 비교하기
	// (그곳으로 갔을 때 기존에 방문한 곳일 경우, 기존 dp[y][x]값보다 낮음
	// 생존일을 누적

	// 시작점 기준 상(y-1, x), 기존에 방문한 적 없음
	if ((y - 1 > 0) && (input[y - 1][x] > input[y][x])) {
		dp[y][x] = max(dp[y][x], panda(y - 1, x) + 1);
	}

	// 시작점 기준 하(y+1, x), 기존에 방문한 적 없음
	if ((y + 1 <= n) && (input[y + 1][x] > input[y][x])) {
		dp[y][x] = max(dp[y][x], panda(y + 1, x) + 1);
	}

	// 시작점 기준 좌(y, x-1), 기존에 방문한 적 없음
	if ((x - 1 > 0) && (input[y][x - 1] > input[y][x])) {
		dp[y][x] = max(dp[y][x], panda(y, x - 1) + 1);
	}

	// 시작점 기준 우(y, x+1), 기존에 방문한 적 없음
	if ((x + 1 <= n) && (input[y][x + 1] > input[y][x])) {
		dp[y][x] = max(dp[y][x], panda(y, x + 1) + 1);
	}

	// up, down, left, right 중 가장 큰 값을 반환함
	return dp[y][x];
}

int main(void)
{
	// 입력받기
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> input[i][j];
		}
	}

	// 2중 loop를 돌면서 panda(i,j) 호출
	// panda(i,j)는 dp[i][j]를 채우는 것과 동일
	// 이 값(dp[i][j]이 max보다 클 경우 갱신
	// 최종 답안은 max
	int max = -99999;
	int temp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			temp = panda(i, j);
			if (max < temp) max = temp;
		}
	}

	cout << max;
	return 0;
}