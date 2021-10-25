#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<cstdio>

using namespace std;

string tempstring;
char lastchar1;
char lastchar2;
stack<char> s;
int ans;

int main()
{
	cin >> tempstring;
	if(tempstring.size() < 3)
	{
		cout << "0 " << tempstring;
		return 0;
	}
	lastchar1 = tempstring[0];
	lastchar2 = tempstring[1];
	s.push(lastchar1);
	s.push(lastchar2);
	for(int i = 2; i < tempstring.size(); i++)
	{
		if(lastchar1 == lastchar2 && lastchar2 == tempstring[i])
		{
			ans++;
			s.pop();
			s.pop();
			if(s.empty() == 1)
			{
				lastchar1 = '.';
				lastchar2 = '.';
				continue;
			}
			lastchar2 = s.top();
			s.pop();
			if(s.empty() == 1)
			{
				lastchar1 = '.';
				s.push(lastchar2);
				continue;
			}
			lastchar1 = s.top();
			s.push(lastchar2);
			continue;
		}else
		{
			s.push(tempstring[i]);
			lastchar1 = lastchar2;
			lastchar2 = tempstring[i];
		}
	}
	cout << ans << " ";
	if(s.empty() == 1)
	{
		cout << "qwq";
		return 0;
	}
	string temp = "";
	while(s.empty() != 1)
	{
		char tempchar = s.top();
		temp = tempchar + temp;
		s.pop();
	}
	cout << temp;
	return 0;
} 
