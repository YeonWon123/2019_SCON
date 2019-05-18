#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// 알고리즘

//1. 힘과 지능은 모두 1로 시작합니다.
//
//2. 현재 힘과 지능을 통해 깰 수 있는 퀘스트의 수를 구합니다.
//
//->이 때, 새로 클리어하는 퀘스트의 보상(포인트)의 누적합을 구합니다.
//
//3. 2번에서 구한 포인트의 누적합을 힘과 지능에 투자할 수 있는 모든 경우의 수를 고려하여 다시 재귀함수를 호출합니다.
//
//4. 3번에서 구한 퀘스트의 수 중 최대값을 반환합니다

const int MAX = 100 + 1;

int N;

pair<pair<int, int>, int>arr[MAX];  // 힘, 지능, 포인트

// pair 
//pair< type1 , type2> p

// 사용할 데이터 타입 1, 2를 넣고  그 타입의 pair 클래스인 p를 만든다.
// p.first : p의 첫번째 인자 반환
// p.second: p의 두번째 인자 반환
// make_pair(변수1,변수2) : 변수1 과 변수2가 들어간 pair를 만들어준다.
// sort 알고리즘에 의해 정렬이 가능하다.

int cache[1000 + 1][1000 + 1]; // 힘, 지능
bool visited[MAX];  // 방문했는지를 true false로 표현

int maxQuest(int strength, int intelligence)
{
	int &result = cache[strength][intelligence];
	if (result != -1)
		return result;

	int point = 0;// 추가 포인트
	int cnt = 0; // 클리어한 퀘스트

	vector<int>v;

	for (int i = 0; i < N; i++)
	{
		//클리어할 수 있는 퀘스트 수
		if (arr[i].first.first <= strength || arr[i].first.second <= intelligence)
		{
			if (!visited[i])  // 그중에서도 아직 클리어하지 않은 퀘스트
			{
				visited[i] = true;
				v.push_back(i);  // true로 변환 인덱스를 벡터에 저장  --> 나중에 초기화를 위해
				point += arr[i].second;
			}

			cnt++;
		}
	}

	result = cnt;

	// 힘과 지능에 올릴 수 있는 모든 경우의 수 고려

	for (int i = strength; i <= min(1000, strength + point); i++)

		result = max(result, maxQuest(i,min(1000, intelligence + (point - (i - strength)))));

	//초기화
	for (int i = 0; i < v.size(); i++)
		visited[v[i]] = false;  

	return result;

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;

	memset(cache, -1, sizeof(cache));
	cout << maxQuest(1, 1) << "\n";

	system("pause");
	return 0;
}