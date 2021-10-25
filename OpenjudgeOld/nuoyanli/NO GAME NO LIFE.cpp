#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<iomanip>

using namespace std;

int l,c,n;
string s[233];
map<string,bool> m;
map<string,int> mpos;
int nextx[10] = {0,1,0,1,1,-1,-1,-1,0};
int nexty[10] = {0,0,1,1,-1,-1,1,0,-1};
set<int> v[60][60];
int ans;

void work(int strx,int stry)
{
	for(int i = 1; i <= 8; i++)
	{
		string temps = "";
		int nowx = strx;
		int nowy = stry;
		while(nowx <= l && nowy < c && nowy >= 0 && nowx >= 0)
		{
			temps = temps + s[nowx][nowy];
			sort(temps.begin(),temps.end());
			if(m[temps] == 1)
			{
				//cout << temps << endl;
				//cout << strx << " " << stry << endl;
				int tempx = strx;
				int tempy = stry;
				while(1)
				{
					v[tempx][tempy].insert(mpos[temps]);
					if(tempx == nowx && tempy == nowy)
						break;
					tempx += nextx[i];
					tempy += nexty[i];
				}
			}
			nowx += nextx[i];
			nowy += nexty[i];	
		}
	}	
}

int main()
{
	//freopen("7.in","r",stdin);
	cin >> l >> c;
	for(int i = 1; i <= l; i++)
		cin >> s[i];
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		string temp;
		cin >> temp;
		sort(temp.begin(),temp.end());
		m[temp] = 1;
		mpos[temp] = i;
	}
	for(int i = 1; i <= l; i++)
	for(int j = 0; j < c; j++)
		work(i,j);
	for(int i = 1; i <= l; i++)
    {
        for(int j = 0; j < c; j++)
        if(v[i][j].size() < 2)
            cout << setw(3) << v[i][j].size();
        cout << endl;
    }
	for(int i = 1; i <= l; i++)
	for(int j = 0; j < c; j++)
		if(v[i][j].size() >= 2)
			ans++;
	cout << ans;
	return 0;
}