// DP[i][j] = i~j���� ������ �ּ� ��ȯ Ƚ��



#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <set>
#include <list>
#include <utility>
#include <functional>
#define MAX 205
#define INF 987654321
#define MOD 1000000
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int n, m, arr[MAX], dp[MAX][MAX];

int fun(int s, int f)
{
	if (s == f)
		return 0;
	if (dp[s][f] != -1)
		return dp[s][f];
	// ������ s~f ���� ������ ����ġ ��ȯ Ƚ���� ���ߴٸ�
	dp[s][f] = INF;
	for (int i = s; i < f; i++)
	{
		int tmp = arr[s] != arr[i + 1] ? 1 : 0;
		dp[s][f] = min(dp[s][f], fun(s, i) + fun(i + 1, f) + tmp);
		// s~f������ �ּ� ��Ⱥ Ƚ�� = s~i, i+1~f ������ �ּ� ��ȯ Ƚ�� + tmp
	}
	return dp[s][f];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d", fun(1, n));
	return 0;
}
