#include<iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio;
    cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;  // 밀가루의 키로수를 입력받는다.
    cin >> N;
	int a = N / 5;
	

	if (N % 5 == 0)
	{
		cout << N / 5;
		return 0;
	}

	
	for (; a > 0; a--)
	{

		
	   if (((N - a * 5) % 3) == 0)
		{
		   cout << a + (N - a * 5) / 3 << "\n";
		   return 0;
		}
	}

	cout << -1;


	return 0;
}