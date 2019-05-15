// 1-D array DP Ǯ��

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

vector<vector<int> > adj;
int dp[1001];
int buildtime[1001];

int func(int here) {
	
	int &ret = dp[here];
	if (ret != -1) return ret;

	ret = buildtime[here];
	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];
		ret = max(ret, buildtime[here] + func(next));
	}

	return ret;
}

int main() {

	int T;
	scanf("%d", &T);

	while (T--) {
		int n, k;
		scanf("%d %d", &n, &k);

		// �ʱ�ȭ
		adj.resize(n + 1);
		memset(dp, -1, sizeof(dp));

		// �ð� �Է�
		for (int i = 1; i <= n; i++)
			scanf("%d", &buildtime[i]);

		// ���� �Է�
		while (k--) {
			int a, b;
			scanf("%d %d", &a, &b);

			// edge : a to b
			adj[b].push_back(a);
		}

		int p;
		scanf("%d", &p);

		printf("%d\n", func(p));

		adj.clear();
	}

	return 0;
}