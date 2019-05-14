#include <iostream>
using namespace std;

int x[100000];
int y[100000];

int dist(int x1, int y1, int x2, int y2) {
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	int ans = -1;

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int d = dist(x[i], y[i], x[j], y[j]);

			if (ans == -1 || ans > d) {
				ans = d;
			}
		}
	}

	cout << ans;
	return 0;
}