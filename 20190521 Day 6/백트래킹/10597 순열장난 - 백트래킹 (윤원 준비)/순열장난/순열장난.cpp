// O(...) 대략 (n/2)C9
// n을 정하고 모든 경우를 조사


#include <cstdio>
#include <cstdlib>
#include <cstring>

char s[92];
int len, n, r[50], ck[51];
void f(int h, int p, int x) {
	if (p == n) {
		for (int i = 0; i < n; i++) printf("%d ", r[i]);
		exit(0);
	}
	x = x * 10 + s[h] - '0';
	if (!x || x > n) return;
	if (!ck[x]) {
		ck[x] = 1;
		r[p] = x;
		f(h + 1, p + 1, 0);
		ck[x] = 0;
	}
	f(h + 1, p, x);
}

int main() {
	scanf("%s", s);
	len = strlen(s);
	n = len < 10 ? len : 9 + (len - 9) / 2;
	f(0, 0, 0);
	return 0;
}