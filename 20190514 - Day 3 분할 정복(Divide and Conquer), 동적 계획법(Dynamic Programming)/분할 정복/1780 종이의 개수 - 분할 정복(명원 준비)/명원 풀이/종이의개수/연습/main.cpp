#include <iostream>
#include <math.h>
using namespace std;
void recursion( int N,int i, int j);


int a, b, c = 0; // -1,0,1의 종이를 카운터하는 숫자
int num = 0; // 처음 9개로 나누어지는 한개당 종이의 한변의 길이

int object,object2 = 0;
int ary[2187][2187];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// NxN행렬을 만들기 위한 N을 입력한다.

	int N;
	cin >> N;
 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> ary[i][j];
			
		}
		
	}

    
	recursion( N, 0, 0);
    cout << a << "\n" << b << "\n" << c;

	return 0;
}

void recursion(int N, int i, int j) // i,j는 시작주소
{                                               // N은 끝주소

	int sum = 0;// 배열의 모든 합
	num = sqrt(N * N / 9);  // 9개로 나누어 주었을 때의  한변길이

	object = num;
	object2 = num;


	for (int a = i; a < i+N; a++)
	{
		for (int b = j; b < j+N; b++)
		{

			sum += ary[a][b];

		}

	}
		
	cout << sum << " ";

		if (sum == (N * N))
			c++;
			
		else if (sum == -(N*N))
			a++;
			
		else if (sum == 0)
		{
			for (int a = i; a < N+i; a++)  // sum이 0이지만 1과 -1이 상쇄되는 경우   
			{
				for (int b = j; b < j+N; b++)
				{
					if (ary[a][b] == -1)
					{
						ary[a][b] = 1;  // -1일 경우 1로 바꾸어서 다더해준다	
					}
					sum += ary[a][b];
				}
			}

			if (sum == 0)	
			b++;	
		}

		else {

			for (int i = 0; object < N; i++) // 시작점을 찾아주는 이차원 배열
			{
				object = num * i;

				for (int j = 0; object2 < N; j++)
				{

					object2 = num * j;
					recursion(num, object, object2);

				}
			}

		}
	
		


		return;
	
		
	}
