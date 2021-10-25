#include<iostream>

using namespace std;

int n;
int s[1000010];
int ans;

void get()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	return;
}

void work()
{
	for(int i = 1; i <= n; i++)
		ans = ans xor s[i];
	return;
}

void put()
{
	cout << ans << endl;
	return;
}

int main()
{
	get();
	work();
	put();
	return 0;	
} 
