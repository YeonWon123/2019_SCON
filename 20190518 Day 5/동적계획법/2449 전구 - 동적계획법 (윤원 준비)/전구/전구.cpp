/*
O(n3)

dp[i][j]를[i, j] 구간에 있는 전구의 색을 하나로 만들기 위한 바꾸는 횟수의 최솟값이라고 정의하자.
그러면 dp[i][j]는 i <= k < j인 임의의 k에 대해[i, k]와[k + 1, j] 구간 각각을 먼저 같은 색으로 만든 후, 
두 구간을 같은 색으로 만드는 최적의 방법 중에 해가 존재한다.
또한, 전구의 색을 바꿀 때 오른쪽 전구의 색을 왼쪽 전구의 색으로 바꾸기만 해도
최적의 횟수로 전구의 색을 통일시킬 수 있기 때문에 
어떤[x, y] 구간을 같은 색으로 만들었다면 그 색은 원래의 x번째 전구 색이라고 가정해도 된다.

	이에 따라
	dp[i][j] = min(dp[i][k] + dp[k + 1][j] + (i번, k + 1번 전구의 색이 다르면 1 같으면 0))
*/

#include<cstdio>
#include<algorithm>
using namespace std;
int n, a[200], dp[200][200];
int main() {
	scanf("%d%*d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		for (int j = i; j--;) {
			dp[j][i] = 1e9;
			for (int k = j; k < i; k++)
				dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i] + (a[j] != a[k + 1]));
		}
	}
	printf("%d", dp[0][n - 1]);
	return 0;
}
