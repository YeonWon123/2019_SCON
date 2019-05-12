/*
집합 {0, 1, 2, 3, 4, 5, 6, 7, 9}에서 공집합이 아닌 임의의 부분집합을 생각해봅시다.
예를 들어 {1, 3, 5, 9}라고 할 때 이 집합에 대응되는 감소하는 수는 무조건 1개로 고정됩니다.
수를 감소하게 둬야하기 때문이죠. 그렇기 때문에 감소하는 수는 2^{10}-1 = 10232 10?1=1023개밖에 없음을 알 수가 있습니다. 
그러면 이제 N번째 수를 어떻게 알아내는지가 문제인데, 저는 그냥 1023개의 수를 일단 구한다음 정렬하는 방식으로 해결했습니다.
이렇게 하지 않고 직접 카운팅을 하려고 들면 너무 코드가 더러워질 것 같아서요.
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
	vector<long long> dec_num;
	for (int i = 1; i <= 1023; i++) { // {0, 1, 2, 3, .. , 9}의 공집합이 아닌 부분집합을 뽑아내기 위해서.
		long long num = 0; // i에 대응되는 감소하는 수
		int tmp_i = i;
		for (int idx = 9; idx >= 0; idx--) {
			if (tmp_i % 2 == 1)
				num = 10 * num + idx; // idx를 1의 자리에 넣음
			tmp_i /= 2;
		}
		dec_num.push_back(num); // i에 대응되는 감소하는 수를 list에 넣음
	}
	sort(dec_num.begin(), dec_num.end());
	int N;
	scanf("%d", &N);
	if (N > 1022)
		printf("-1");
	else
		printf("%lld", dec_num[N]);
	return 0;
}