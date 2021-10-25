#include<iostream>

using namespace std;

int a,b,c;
bool ok[10000000];

int main()
{
	for(int nown = 1; nown <= 10; nown++)
	for(int a = 0; a <= nown; a++)
	for(int b = 0; b <= nown; b++)
	for(int c = 0; c <= nown; c++)
	{
		for(int i = 1; i <= 10000; i++)
			ok[i] = 0;
		for(int k = 0; k <= c; k++)
		for(int j = 0; j <= b; j++)
		for(int i = 0; i <= a; i++)
			ok[i+2*j+5*k] = 1;
		for(int i = 1; i <= 10000; i++)
			if(ok[i] == 0)
			{
				cout << a << " " << b << " " << c << " " << i << endl;;
				break;
			}
	}
	return 0;
}
