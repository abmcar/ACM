#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>

using namespace std;

string tempstring;
bool first;

void work()
{
	if(first == 0)
		first = 1;
	else
		cout << " ";
	for(int i = tempstring.size()-1; i >= 0; i--)
		cout << tempstring[i];
	return;
}

int main()
{
	while(cin >> tempstring)
		work();	
	return 0;
}
