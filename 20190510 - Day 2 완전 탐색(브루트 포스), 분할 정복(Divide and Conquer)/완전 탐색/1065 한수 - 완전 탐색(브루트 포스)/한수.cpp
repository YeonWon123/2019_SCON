#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	// �Է����� ���� �ڸ� ���� �Ǵ� ���� �ڸ� ���ڰ� ���´ٸ�
	if (N < 100) {
		cout << N;
		return 0;
	}
	else if (N == 1000) { // �Է����� 1000�� ���´ٸ� (Ư���� ���)
		cout << 144;	// ������ ���°�ó�� 144 ���
		return 0;
	}
	else { // �Է����� ���� �ڸ� ���� ���´ٸ�
		// �ڸ����� �̾ƺ���.
		int pos[3];
		int counts = 0;
		// pos[0]���� ���� �ڸ� ���ڰ�, pos[1]���� ���� �ڸ� ���ڰ�, pos[2]���� ���� �ڸ� ���ڰ�
		// �� �� �ְ� �غ���
		// ������ ���� (/) or ������ ���� (%) �� �̿��� ���� �ִ�.
		for (int i = 100; i <= N; i++) {
			// 123�� ���
			pos[0] = i / 100;						    // 1 = 123/100
			pos[1] = (i - 100 * pos[0]) / 10;		    // 2 = (123 - 100 * 1) / 10
			pos[2] = (i - 100 * pos[0] - 10 * pos[1]);	// 3 = (123 - 100 * 1 - 10 * 2)

			if ((pos[0] - pos[1]) == (pos[1] - pos[2])) {
				counts++;
			}
		}

		cout << counts + 99;
		return 0;
	}
	
	return 0;
}