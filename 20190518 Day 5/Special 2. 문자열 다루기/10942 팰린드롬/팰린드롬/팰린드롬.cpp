#include <iostream>
using namespace std;

int input[2000];
int DP[2000][2000] = { 0, };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	// DP �迭 ä���
	// �ʱ�ȭ - ���ڸ�
	for (int i = 0; i < N; i++) {
		DP[i][i] = 1;
	}

	// �ʱ�ȭ - ���ڸ�
	for (int i = 0; i < N - 1; i++) {
		if (input[i] == input[i+1])
			DP[i][i + 1] = 1;
	}

	// �ʱ�ȭ - ���ڸ� ~ n�ڸ�
	for (int i = 2; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			if ((input[j] == input[j + i]) && (DP[j+1][j+i-1])) {
				DP[j][j+i] = 1;
			}
		}

	}

	pair<int, int> q; // question
	
	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> q.first >> q.second;
		cout << DP[q.first-1][q.second-1] << "\n";
	}

	return 0;
}