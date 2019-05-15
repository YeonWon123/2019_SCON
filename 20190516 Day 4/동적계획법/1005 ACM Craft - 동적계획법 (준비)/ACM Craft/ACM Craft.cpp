// 2-D array DP 풀이

#include <iostream>
#include <algorithm>
#include <cstring> //memset
using namespace std;

int N; //최대 1000
int cache[1001];
int delay[1001]; //건물 짓는데 걸리는 시간
int order[1001][1001]; //건물 짓는 조건 -> DP 배열에 해당

int totalTime(int destination)
{
	int &result = cache[destination];
	if (result != -1)
		return result;
	int time = 0;

	// 밑에서부터 올라가면서 DP 순회
	for (int i = 1; i <= N; i++)
		if (order[i][destination])
			time = max(time, totalTime(i)); //destination을 만들기 전에 동시에 만들 건물 중 제일 시간 오래 걸리는 건물
	return result = time + delay[destination];
}

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int K, D, X, Y;
		cin >> N >> K; //최대 건물 수, 조건 수

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