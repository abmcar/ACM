#include<iostream>
#include<string>

using namespace std;

int n;
string s[600];
int k[20] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int fin[20] = {1,0,10,9,8,7,6,5,4,3,2};
bool check(string sfz)
{
	int ans = 0;
	for(int i = 0; i < sfz.size(); i++)
		ans += ((int)sfz[i]-48) * k[i];
	ans = ans % 11;
	if(fin[ans] == 10)
	{
		if(sfz[17] == 'X')
			return true;
		else
			return false;
	}
	if(fin[ans] == (int)sfz[17]-48)
		return true;
	else
		return false;
}

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
		if(check(s[i]) == true)
			cout << "True" << endl;
		else
			cout << "False" << endl;
	return;
}

int main()
{
	get();
	work();
	return 0;	
}
