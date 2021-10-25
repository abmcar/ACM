#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int n;

int work(string nowstring)
{
	if(nowstring.size() == 1)
		return 1;
	if(nowstring.size() % 2 == 1)
		return nowstring.size();
	for(int i = 0; i < nowstring.size()/2; i++)
		if(nowstring[i] != nowstring[nowstring.size()-1-i])
			return nowstring.size();
	string te = "";
	for(int i = 0; i < nowstring.size()/2; i++)
		te = te + nowstring[i];
	return work(te);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string temp;
		cin >> temp;
		if(temp.size() % 2 == 1)
			cout << temp.size() << endl;
		else
			cout << work(temp) << endl;
	}
    return 0;
}
