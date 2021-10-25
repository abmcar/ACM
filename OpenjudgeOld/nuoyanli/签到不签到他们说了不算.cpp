#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n;

void work()
{
	int minx = 66666;
	int maxx = 0;
	int miny = 66666;
	int maxy = 0;
	string temp[6666];
	for(int i = 1; i <= n; i++)
	{
		cin >> temp[i];
		for(int j = 0; j < temp[i].size(); j++)
		{
			if(temp[i][j] == '*')
			{
				minx = min(minx,i);
				maxx = max(maxx,i);
				miny = min(miny,j);
				maxy = max(maxy,j);
				//cout << minx << " " << maxx << " " << miny << " " << maxy << endl;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < temp[i].size(); j++)
		{
			if(i >= minx && i <= maxx)
			if(j >= miny && j <= maxy)
			if(temp[i][j] == '.')
			{
				cout << "*";
				continue;
			}
			if(temp[i][j] == '*')
			{
				cout << ".";
				continue;
			}
			cout << temp[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return;	
}

int main()
{
	while(cin >> n)
		work();
}
