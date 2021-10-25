#include<iostream>
#include<string>

using namespace std;

struct student
{
	string name;
	int pos;
}s[20020];
int n,m,k;
int father[20020];

void get()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i].name;
		s[i].pos = i;
	}
}

int find(int son)
{
	if(father[son] == son)
		return son;
	father[son] = find(father[son]);
	return father[son];
}

int getpos(string temp)
{
	for(int i = 1; i <= n; i++)
		if(s[i].name == temp)
			return s[i].pos;
}

void work()
{
	for(int i = 1; i <= n; i++)
		father[i] = i;
	for(int i = 1; i <= m; i++)
	{
		string a1,a2;
		cin >> a1 >> a2;
		father[find(getpos(a1))] = find(getpos(a2));
	}
	cin >> k;
	for(int i = 1; i <= k; i++)
	{
		string b1,b2;
		cin >> b1 >> b2;
		if(find(getpos(b1)) == find(getpos(b2)))
			cout << "Yes." << endl;
		else
			cout << "No." << endl;
	}
}

int main()
{
	get();
	work();
	return 0;	
}
