// 2-D array DP Ǯ��

#include <iostream>
#include <algorithm>
#include <cstring> //memset
using namespace std;

int N; //�ִ� 1000
int cache[1001];
int delay[1001]; //�ǹ� ���µ� �ɸ��� �ð�
int order[1001][1001]; //�ǹ� ���� ���� -> DP �迭�� �ش�

int totalTime(int destination)
{
	int &result = cache[destination];
	if (result != -1)
		return result;
	int time = 0;

	// �ؿ������� �ö󰡸鼭 DP ��ȸ
	for (int i = 1; i <= N; i++)
		if (order[i][destination])
			time = max(time, totalTime(i)); //destination�� ����� ���� ���ÿ� ���� �ǹ� �� ���� �ð� ���� �ɸ��� �ǹ�
	return result = time + delay[destination];
}

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int K, D, X, Y;
		cin >> N >> K; //�ִ� �ǹ� ��, ���� ��

		for (int j = 1; j <= N; j++)
			cin >> delay[j];

		memset(cache, -1, sizeof(cache));
		memset(order, 0, sizeof(order));

		for (int j = 0; j < K; j++)
		{
			cin >> X >> Y; //source, destination
			order[X][Y] = 1;
		}

		cin >> D;
		if (D < 0 || D>100000)
			exit(-1);

		cout << totalTime(D) << endl;
	}
	return 0;
}