#include <iostream>
using namespace std;

struct mess {
	int weight; // ������
	int height; // Ű
	int answer; // ���
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

	// ��� ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue; // ���� ���� ���� �ʿ�� ����
			if ((input[i].weight < input[j].weight) && (input[i].height < input[j].height)) {
				input[i].answer++;
			}
		} 
		cout << input[i].answer + 1 << " ";
	}

	return 0;
}