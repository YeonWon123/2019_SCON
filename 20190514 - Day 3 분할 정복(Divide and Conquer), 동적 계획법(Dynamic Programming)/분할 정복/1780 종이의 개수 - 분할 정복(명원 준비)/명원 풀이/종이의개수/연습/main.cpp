#include <iostream>
#include <math.h>
using namespace std;
void recursion( int N,int i, int j);


int a, b, c = 0; // -1,0,1�� ���̸� ī�����ϴ� ����
int num = 0; // ó�� 9���� ���������� �Ѱ��� ������ �Ѻ��� ����

int object,object2 = 0;
int ary[2187][2187];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// NxN����� ����� ���� N�� �Է��Ѵ�.

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

void recursion(int N, int i, int j) // i,j�� �����ּ�
{                                               // N�� ���ּ�

	int sum = 0;// �迭�� ��� ��
	num = sqrt(N * N / 9);  // 9���� ������ �־��� ����  �Ѻ�����

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
			for (int a = i; a < N+i; a++)  // sum�� 0������ 1�� -1�� ���Ǵ� ���   
			{
				for (int b = j; b < j+N; b++)
				{
					if (ary[a][b] == -1)
					{
						ary[a][b] = 1;  // -1�� ��� 1�� �ٲپ �ٴ����ش�	
					}
					sum += ary[a][b];
				}
			}

			if (sum == 0)	
			b++;	
		}

		else {

			for (int i = 0; object < N; i++) // �������� ã���ִ� ������ �迭
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
