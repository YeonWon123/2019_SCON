#include <iostream>
#include <string>
#include <algorithm>
#include <cstring> // memset
using namespace std;


int cache[1000][1000];
string s1, s2;


int LCS(int idx1, int idx2)
{
	// 기저사례
	if (idx1 == s1.size() || idx2 == s2.size())
		return 0;

	int &result = cache[idx1][idx2];
	if (result != -1)
		return result;

	// 총 3가지의 경우의 수를 고려
	//1. s1만 인덱스가 증가할 경우
	//2. s2만 인덱스가 증가할 경우
	//3. s1,s2 인덱스가 둘다 증가할 경우

return result = max(LCS(idx1 + 1, idx2), max(LCS(idx1, idx2 + 1), LCS(idx1 + 1, idx2 + 1) + (s1[idx1] == s2[idx2])));
}
	
int main(void)
{
	cin >> s1>> s2;
	memset(cache, -1, sizeof(cache));
	cout << LCS(0, 0) << endl;
	
	system("pause");
	return 0;
}