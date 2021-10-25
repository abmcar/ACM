#include<iostream>
#include<cmath>
using namespace std;

int num;

int isprime (int n)
{
    int flag,i;
    flag=1;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            flag=0;
            break;
        }
    }
    return flag;
}


int main()
{
	cin >> num;
	for(int i = 1; i <= num; i++)
	{
		int temp;
		cin >> temp;
		if(isprime(temp) == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
} 
