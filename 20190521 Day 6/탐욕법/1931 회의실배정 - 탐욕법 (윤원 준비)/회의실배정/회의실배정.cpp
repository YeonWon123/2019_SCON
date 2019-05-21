#include <iostream>
#include <algorithm>
using namespace std;

pair <int, int> input[100000];

// ȸ�ǰ� ���� ������ ������ ����
// ���� ȸ�ǰ� ������ �ð��� ������,
// ȸ���� ���� �ð��� ���� ������ ����
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

	// ȸ�ǰ� ���� ������ ������ ����
	// ���� ȸ�ǰ� ������ �ð��� ������,
	// ȸ���� ���� �ð��� ���� ������ ����
	sort(input, input + N, comp);

	// �׷��� �� ���� data�� ������ ȸ�ǽ�Ű��
	// �߰��� ȸ�ǰ� �ִ� ����� �ݷ���Ű�� ��
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