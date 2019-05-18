#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// �˰���

//1. ���� ������ ��� 1�� �����մϴ�.
//
//2. ���� ���� ������ ���� �� �� �ִ� ����Ʈ�� ���� ���մϴ�.
//
//->�� ��, ���� Ŭ�����ϴ� ����Ʈ�� ����(����Ʈ)�� �������� ���մϴ�.
//
//3. 2������ ���� ����Ʈ�� �������� ���� ���ɿ� ������ �� �ִ� ��� ����� ���� ����Ͽ� �ٽ� ����Լ��� ȣ���մϴ�.
//
//4. 3������ ���� ����Ʈ�� �� �� �ִ밪�� ��ȯ�մϴ�

const int MAX = 100 + 1;

int N;

pair<pair<int, int>, int>arr[MAX];  // ��, ����, ����Ʈ

// pair 
//pair< type1 , type2> p

// ����� ������ Ÿ�� 1, 2�� �ְ�  �� Ÿ���� pair Ŭ������ p�� �����.
// p.first : p�� ù��° ���� ��ȯ
// p.second: p�� �ι�° ���� ��ȯ
// make_pair(����1,����2) : ����1 �� ����2�� �� pair�� ������ش�.
// sort �˰��� ���� ������ �����ϴ�.

int cache[1000 + 1][1000 + 1]; // ��, ����
bool visited[MAX];  // �湮�ߴ����� true false�� ǥ��

int maxQuest(int strength, int intelligence)
{
	int &result = cache[strength][intelligence];
	if (result != -1)
		return result;

	int point = 0;// �߰� ����Ʈ
	int cnt = 0; // Ŭ������ ����Ʈ

	vector<int>v;

	for (int i = 0; i < N; i++)
	{
		//Ŭ������ �� �ִ� ����Ʈ ��
		if (arr[i].first.first <= strength || arr[i].first.second <= intelligence)
		{
			if (!visited[i])  // ���߿����� ���� Ŭ�������� ���� ����Ʈ
			{
				visited[i] = true;
				v.push_back(i);  // true�� ��ȯ �ε����� ���Ϳ� ����  --> ���߿� �ʱ�ȭ�� ����
				point += arr[i].second;
			}

			cnt++;
		}
	}

	result = cnt;

	// ���� ���ɿ� �ø� �� �ִ� ��� ����� �� ���

	for (int i = strength; i <= min(1000, strength + point); i++)

		result = max(result, maxQuest(i,min(1000, intelligence + (point - (i - strength)))));

	//�ʱ�ȭ
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