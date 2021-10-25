#include <iostream>
#include <algorithm>
using namespace std;

int mA[32][3][3];//幂矩阵
int tA[3][3];//临时存储矩阵
int A[3];//A[0] 均为偶数的方案数  A[1] 一奇一偶的方案数  A[2] 均为奇数的方案数

int main()
{
	int T, N, sum;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mA[0][i][j] = 1;
		}
	}

	mA[1][0][0] = 2;
	mA[1][0][1] = 1;
	mA[1][0][2] = 0;
	mA[1][1][0] = 2;
	mA[1][1][1] = 2;
	mA[1][1][2] = 2;
	mA[1][2][0] = 0;
	mA[1][2][1] = 1;
	mA[1][2][2] = 2;

	for (int i = 2; i < 32; i++)
	{
		for (int k1 = 0; k1 < 3; k1++)
		{
			for (int k2 = 0; k2 < 3; k2++)
			{
				sum = 0;
				for (int j = 0; j < 3; j++)
				{
					sum += mA[i - 1][k1][j] * mA[i - 1][j][k2];
				}
				tA[k1][k2] = sum % 10007;
			}
		}
		for (int k1 = 0; k1 < 3; k1++)
		{
			for (int k2 = 0; k2 < 3; k2++)
			{
				mA[i][k1][k2] = tA[k1][k2];
			}
		}
	}

	cin >> T;

	for (int so = 0; so < T; so++)
	{
		int i = 0;
		A[0] = 1;
		A[1] = 0;
		A[2] = 0;

		cin >> N;

		while (N)
		{
			i++;

			if (N & true)
			{
				for (int k1 = 0; k1 < 3; k1++)
				{
					sum = 0;
					for (int j = 0; j < 3; j++)
					{
						sum += A[j] * mA[i][k1][j];
					}
					tA[0][k1] = sum % 10007;
				}

				for (int k1 = 0; k1 < 3; k1++)
				{
					A[k1] = tA[0][k1];
				}
			}
			N >>= 1;
		}

		cout << A[0] << '\n';
	}

	return 0;
}