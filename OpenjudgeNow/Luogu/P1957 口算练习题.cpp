#include<iostream>
#include<string>

using namespace std;

int n;
char lastfh;

int turnint(string tempstring)
{
	int tempnum = tempstring[0]-'0';
	for(int i = 1; i < tempstring.size(); i++)
	{
		tempnum *= 10;
		tempnum += tempstring[i]-'0';
	}
	return tempnum;
}

string turnstring(int tempnum)
{
	bool endadd = false;
	string tempstring = "";
	if(tempnum == 0)
		return "0";
	if(tempnum < 0)
	{
		endadd = true;
		tempnum *= -1;
	}
	while(tempnum != 0)
	{
		int tempn = tempnum % 10;
		tempnum /= 10;
		char temps = tempn+'0';
		tempstring = temps+tempstring;
	}
	if(endadd == true)
		tempstring = "-" + tempstring;
	return tempstring;
}

int slove(char tempfh,int tempnuma,int tempnumb)
{
	if(tempfh == '+')
		return tempnuma+tempnumb;
	if(tempfh == '-')
		return tempnuma-tempnumb;
	if(tempfh == '*')
		return tempnuma*tempnumb;
	if(tempfh == '/')
		return tempnuma/tempnumb;
}

void work()
{
	string temp;
	int ta,tb;
	int ans;
	int length;
	cin >> temp;
	if(temp == "a" || temp == "b" || temp == "c" || temp == "d")
	{
		if(temp == "a")
			lastfh = '+';
		if(temp == "b")
			lastfh = '-';
		if(temp == "c")
			lastfh = '*';
		if(temp == "d")
			lastfh = '/';
		cin >> ta >> tb;
		ans = slove(lastfh,ta,tb);
		length = turnstring(ta).size()+turnstring(tb).size()+2+turnstring(ans).size();
		cout << turnstring(ta)+lastfh+turnstring(tb)+"="+turnstring(ans) << endl << length << endl;
		return;
	}
	ta = turnint(temp);
	cin >> tb;
	ans = slove(lastfh,ta,tb);
	length = turnstring(ta).size()+turnstring(tb).size()+2+turnstring(ans).size();
	cout << turnstring(ta)+lastfh+turnstring(tb)+"="+turnstring(ans) << endl << length << endl;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		work();
	return 0;	
} 
