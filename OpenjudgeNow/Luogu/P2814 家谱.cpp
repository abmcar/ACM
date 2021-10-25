#include<iostream>
#include<map>

using namespace std;

map<string,string> people;

string find(string son)
{
	if(people[son] == son)
		return son;
	people[son] = find(people[son]);
	return people[son];	
}

int main()
{
		char temp;
		cin >> temp;
		string tempfather;
		while(temp != '$')
		{
			if(temp == '$')
				break;
			string tempstring;
			cin >> tempstring;
			if(temp == '#')
			{
				tempfather = tempstring;
				if(people[tempstring] == "")
					people[tempstring] = tempstring;
			}
			if(temp == '+')
				people[tempstring] = tempfather;
			if(temp == '?')
				cout << tempstring << " " << find(tempstring) << endl;
			cin >> temp; 
		}
		return 0;
}
