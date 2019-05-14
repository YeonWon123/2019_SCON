#include <iostream>
using namespace std;

struct mess {
	int weight; // 몸무게
	int height; // 키
	int answer; // 등수
	mess() {
		answer = 0;
	}
};

int main(void)
{
	int N;
	cin >> N;

	struct mess input[50];

	for (int i = 0; i < N; i++) {
		cin >> input[i].weight >> input[i].height;
	}

	// 등수 계산
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue; // 나랑 나를 비교할 필요는 없다
			if ((input[i].weight < input[j].weight) && (input[i].height < input[j].height)) {
				input[i].answer++;
			}
		} 
		cout << input[i].answer + 1 << " ";
	}

	return 0;
}