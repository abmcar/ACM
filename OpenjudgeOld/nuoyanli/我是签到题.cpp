#include<iostream>
#include<string>

using namespace std;

string tempstring;
int n;

string maxstring(string a,string b)
{
	if(a.size() > b.size())
		return b;
	else
	if(a.size() < b.size())
		return a;
	if(a>b)
		return a;
	else
		return b;
}

void work()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		string lasstring = tempstring;
		string nowstring = tempstring;
		for(int j = 0; j < tempstring.size(); j++)
		{
			string ts = lasstring;
			ts.erase(j,1);
			nowstring = maxstring(ts,nowstring);
			//cout << nowstring << endl;
		}
		tempstring = nowstring;
		//cout << tempstring << endl;
	}
	cout << tempstring << endl;
}

int main()
{
	while(cin >> tempstring)
		work();
	return 0;
}
