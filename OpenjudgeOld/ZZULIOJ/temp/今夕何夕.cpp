#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>

using namespace std;

int nowstr;
string str[10];
int n;
string tempstring;
int ans[10];

int find(string t)
{
	for(int i = 1; i <= nowstr; i++)
		if(str[i] == t)
			return i;
	return -1;
}

void work()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> tempstring;
		if(find(tempstring) == -1)
		{
			nowstr++;
			str[nowstr] = tempstring;
			ans[nowstr]++;
			continue;
		}else
			ans[find(tempstring)]++;
	}
}

void putout(int num)
{
	string now = str[num];
	if(now == "NY")
		cout << "New Year";
	if(now == "ILD")
		cout << "International Labor Day";
	if(now == "TDBF")
		cout << "The Dragon Boat Festival";
	if(now == "ND")
		cout << "National Day";
	return;
}

int main()
{
	for(int i = 1; i <= 6; i++)
		work();
	for(int i = 1; i <= 4; i++)
		if(ans[i] == 6)
		{
			putout(i);
			return 0;
		}
	cout << "What a shame!";
	return 0;
}
