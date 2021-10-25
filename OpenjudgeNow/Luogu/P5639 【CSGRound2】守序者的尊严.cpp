#include<iostream>

using namespace std;

int n;
int pos[1000100];
int t = 1;
int nowflag = 0;

void get()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> pos[i];
	return;
}

void work()
{
	for(int i = 1; i <= n; i++)
	{
		if(pos[i] == nowflag)
			continue;
		t++;
		if(nowflag == 0)
			nowflag = 1;
		else
			nowflag = 0;
	}
}

void put()
{
	cout << t << endl;
	return;
}

int main()
{
	get();
	work();
	put();
	return 0;	
} 
