#include <iostream>
using namespace std;

char input[64][64];
void recursion(int y, int x, int length);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input[i][j];
		}
	}

	recursion(0, 0, N);
	return 0;
}

void recursion(int y, int x, int length) {

	int temp = input[y][x];
	
	int sw = 0;
	for (int i = y; i < y + length; i++) {
		for (int j = x; j < x + length; j++) {
			if (temp != input[i][j]) {
				sw = 1;
				break;
			}
		}

		if (sw == 1)
			break;
	}

	if (sw == 0) {
		if (temp == '0')
			cout << 0;
		else
			cout << 1;
		return;
	}
	else {
		int n_length = length / 2;
		cout << "(";
		recursion(y, x, n_length);
		recursion(y, x + n_length, n_length);
		recursion(y + n_length, x, n_length);
		recursion(y + n_length, x + n_length, n_length);
		cout << ")";
	}
}