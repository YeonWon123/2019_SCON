#include <iostream>
#include <algorithm>
using namespace std;

int A[5000000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N);

	cout << A[K - 1];
	return 0;
}