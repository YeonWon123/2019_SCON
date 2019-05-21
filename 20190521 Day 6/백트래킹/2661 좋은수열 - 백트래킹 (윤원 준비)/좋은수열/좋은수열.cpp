#include <iostream>
#include <string>
using namespace std;

// ��������
// N : 1�� ���  1
// N : 2�� ���  12
// N : 3�� ���  121
// N : 4�� ���  1213
// N : 5�� ���  12131
// N : 6�� ���  121312
// N : 7�� ���  1213121
// N : 8�� ���  1213123 1
// N : 9�� ���  1213123 12
// N : 10�� ��� 1213123 121
// N : 11�� ��� 1213123 1213
// N : 12�� ��� 1213123 12131
// N : 13�� ��� 1213123 121312
// N : 14�� ��� 1213123 1213231
// N : 15�� ��� 1213123 1213231 2
// ...


/*
string�� substr �Լ��� �� �̿��ؾ��ϴ� ��Ʈ��ŷ ����

1. 1, 2, 3���θ� �̷�����Ƿ� �ݺ����� ���� 1, 2, 3�� ���س�����.
2. ������ ���ʷ� ������ ��찡 ���� ���� �����̹Ƿ� ����ϰ� ���α׷� ����
3. substr�� �̿��Ͽ� ������ �κ� ���ڿ��� ������ Ȯ��
*/
int N;
string num;

void recursion(char c, int cnt) {
	// ������ �����ϴ� ��� (���� ���� ������ ���ڰ� ���� ���� ���̴�.)
	if (cnt - 1 == N) {
		cout << num << "\n";
		exit(0);
	}

	num += c;
	for (int i = 1; i <= cnt / 2; i++) {
		string a = num.substr(cnt - i, i);
		string b = num.substr(cnt - i * 2, i);

		// ���� ����
		if (a == b) {
			num.erase(cnt - 1);
			return;
		}
	}

	for (int i = 1; i <= 3; i++) {
		recursion(i + '0', cnt + 1);
	}
	num.erase(cnt - 1); // cnt - 1 �ڸ��� �������� ���� ���
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= 3; i++)
		recursion(i + '0', 1);

	return 0;
}