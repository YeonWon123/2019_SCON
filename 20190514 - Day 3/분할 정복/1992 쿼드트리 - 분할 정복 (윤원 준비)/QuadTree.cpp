#include <iostream>
using namespace std;

char **board;

void divide(int N, int x1, int x2, int y1, int y2);

int main()
{
	int N;
	cin >> N;

	board = new char*[N];
	for (int i = 0; i < N; i++)
		board[i] = new char[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	divide(N, 0, N, 0, N);

	return 0;
}

void divide(int N, int x1, int x2, int y1, int y2)
{
    // 그 범위 안에 있는 수들이 모두 1 또는 0인지 확인
	int sw = 0;
	char temp;
	temp = board[x1][y1];
	for (int k = 0; x1+k < x2; k++)
	{
		for (int n = 0; y1+n < y2; n++)
		{
			if (temp != board[x1 + k][y1 + n])
			{
				sw = 1; break;
			}
		}
		if (sw == 1) break;
	}

	if (sw == 0)
	{
		cout << board[x1][y1];
	}
	else
	{
		if (N != 2)
		{
			cout << "(";
			divide(N / 2, x1, x1 + N / 2, y1, y1 + N / 2);
			divide(N / 2, x1, x1 + N / 2, y1 + N/2, y2);
			divide(N / 2, x1 + N/2, x2, y1, y1 + N / 2);
			divide(N / 2, x1 + N/2, x2, y1 + N/2, y2);
			cout << ")";
		}
		else
		{
			cout << "(";
			for (int k = x1; k < x2; k++)
			{
				for (int n = y1; n < y2; n++)
				{
					cout << board[k][n];
				}
			}
			cout << ")";
		}
	}
}