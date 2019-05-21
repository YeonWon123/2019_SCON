#include <iostream>
#include <algorithm>
using namespace std;

pair <int, int> input[100000];

// 회의가 일찍 끝나는 순으로 정렬
// 만약 회의가 끝나는 시간이 같으면,
// 회의의 시작 시간이 빠른 순으로 정렬
bool comp(pair <int, int> a, pair <int, int> b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second) {
		return a.first < b.first;
	}
	else return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input[i].first >> input[i].second;
	}

	// 회의가 일찍 끝나는 순으로 정렬
	// 만약 회의가 끝나는 시간이 같으면,
	// 회의의 시작 시간이 빠른 순으로 정렬
	sort(input, input + N, comp);

	// 그러면 맨 앞의 data만 꺼내서 회의시키고
	// 중간에 회의가 있는 사람은 반려시키면 됨
	int temp = -1;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		if (input[i].first < temp) continue;
		temp = input[i].second;
		answer++;
	}

	cout << answer;
	return 0;
}