#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int num[1010][1010];
int nownum[1010][1010];

void prework()
{
	int nownum = 1;
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
	{
		num[i][j] = nownum;
		nownum++;
	}
	return;
}

inline void work(int x,int y,int r,int z)
{
	if(r == 0)
		return;
	for(int i = x-r; i <= x+r; i++)
	for(int j = y-r; j <= y+r; j++)
	{
		int px = i-x;
		int py = j-y;
		int c;
		c = px;
		px = py;
		py = c;
		if(z == 0)
			py *= -1;
		else
			px *= -1;
		//swap(num[i][j],num[x+px][y+py]);
		nownum[x+px][y+py] = num[i][j];
	}
	for(int i = x-r; i <= x+r; i++)
	for(int j = y-r; j <= y+r; j++)
		num[i][j] = nownum[i][j];
}

inline void output()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			cout << num[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	prework();
	for(int i = 1; i <= m; i++)
	{
		int tx,ty,tr,tz;
		cin >> tx >> ty >> tr >> tz;
		work(tx,ty,tr,tz);
	}
	output();
	return 0;
} 
