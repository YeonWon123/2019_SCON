#include <iostream>
using namespace std;

int input[2500][2500];
int zero_count = 0;
int pone_count = 0;
int mone_count = 0;

void recursion(int y, int x, int length);

int main(void)
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input[i][j];
		}
	}

	recursion(0, 0, N);
	cout << mone_count << "\n";
	cout << zero_count << "\n";
	cout << pone_count << "\n";
	return 0;
}

void recursion(int y, int x, int length) {
	//cout << y << " " << x << " " << length << "재귀호출!\n";
	int temp;
	int temp2;
	temp = input[y][x];
	
	int sw = 0;
	// length에 대해서, (y,x)에서 시작해서 모든 지점이 동일한 수인지 검사
	for (int i = y; i < y + length; i++) {
		for (int j = x; j < x + length; j++) {
			temp2 = input[i][j];

			if (temp != temp2) {
				sw = 1;
				break;
			}
		}

		if (sw == 1)
			break;
	}

	if (sw == 0) {
		switch (temp) {
			case 0:
				zero_count++;
				break;
			case 1:
				pone_count++;
				break;
			case -1:
				mone_count++;
				break;
		}
		return;
	}

	// 아니면 재귀호출
	int plength = length / 3;
	recursion(y, x, plength);
	recursion(y, x + plength, plength);
	recursion(y, x + 2 * plength, plength);
	recursion(y + plength, x, plength);
	recursion(y + plength, x + plength, plength);
	recursion(y + plength, x + 2 * plength, plength);
	recursion(y + 2 * plength, x, plength);
	recursion(y + 2 * plength, x + plength, plength);
	recursion(y + 2 * plength, x + 2 * plength, plength);
}