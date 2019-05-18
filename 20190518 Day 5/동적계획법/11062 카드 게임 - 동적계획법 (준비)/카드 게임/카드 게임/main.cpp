#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


#define my 0

int dp[2][1001][1001];
int arr[1001];
int answer[10000] = { 0 };
int t, n, i;

int func(int turn, int x, int y)
{
	if (x == y)
	{
		if (turn == my)
			return arr[x];
		else
			return 0;
	}

	int &ref = dp[turn][x][y];
	if (ref != -1)
		return ref;

	if (turn == my)   // ��Ʈ ������  xor : �κ�Ʈ�� �ٸ��� 1 ������ 0
		ref = max(func(turn ^ 1, x + 1, y) + arr[x], func(turn ^ 1, x, y - 1) + arr[y]);
	// �� ���̿��ٸ� ������ ���� ����� ���� �ڵ尡 �־�� �Ѵ�.
	else
		ref = min(func(turn ^ 1, x + 1, y), func(turn ^ 1, x, y - 1));
	// ��� ���̿��ٸ� ��뵵 �ּ��� �÷��̸� �ϱ� ������ ���� ������ �ּҷ� �ϴ� �÷��̸� �� ���̴�.
	return ref;


}


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> t;
	int b = t;  int a = 0;
	while (t--)
	{
		memset(dp, -1, sizeof(dp));

		cin >> n;
		
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

			answer[a] = func(my, 0, n - 1);
			a++;
	}

	for (int i = 0; i < b; i++)
		//cout << answer[i] << "\n";
		

	system("pause");
	return 0;
}