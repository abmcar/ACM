#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int numn[23];
vector<int> zfrom[23];
vector<int> zmember[23];
int zn[23];

void get()
{
	cin >> n;
	for(int i = 1; i <= n-2; i++)
	{
		int ta,tb,tc;
		cin >> ta >> tb >> tc;
		zfrom[ta].push_back(i);		
		zfrom[tb].push_back(i);		
		zfrom[tc].push_back(i);
		zmember[i].push_back(ta);
		zmember[i].push_back(tb);
		zmember[i].push_back(tc);
		numn[ta]++;
		numn[tb]++;
		numn[tc]++;
		zn[i] = 3;
	}
	return;
}

void work()
{
	if(n == 3)
	{
		cout << "1 2 3" << endl;
		return;
	}
	if(n == 4)
	{
		for(int i = 1; i <= n; i++)
		{
			if(numn[i] == 1)
			{
				cout << i << " ";
				break;
			}
		}
		for(int i = 1; i <= n; i++)
			if(numn[i] == 2)
				cout << i << " ";
		for(int i = n; i >= 1; i--)
			if(numn[i] == 1)
			{
				cout << i << " ";
				break;
			}
		return;
	}
	for(int i = n; i >= 1; i--)
		if(numn[i] == 1)
		{
			numn[i] = 3;
			for(int j = 0; j < 2; j++)
				if(numn[zmember[zfrom[i][0]][j]] == 2)
					numn[zmember[zfrom[i][0]][j]]++;
			break;
		}
	for(int k = 1; k <= n; k++)
	for(int i = 1; i <= n; i++)
	{
		if(numn[i] == 1)
		{
			cout << i << " ";
			numn[i]--;
			for(int j = 0; j < zfrom[i].size(); j++)
				zn[zfrom[i][j]]--;
			int tempmin = 10;
			int minpos;
			for(int j = 1; j <= n-2; j++)
			{
				if(zn[j] < 1)
					continue;
				if(zn[j] < tempmin)
				{
					minpos = j;
					tempmin = zn[j];	
				}
			}
			if(zfrom[i].size() > 2)
			{
				int tempmin2 = 10;
				int minpos2;
				for(int j = 1; j <= n-2; j++)
				{
					if(zn[j] < 1 || zn[j] == tempmin)
						continue;
					if(zn[j] < tempmin2)
					{
						minpos2 = j;
						tempmin2 = zn[j];	
					}
				}
				for(int j = 0; j < 3; j++)
				if(numn[zmember[minpos2][j]] == 1)
					continue;
				else
					numn[zmember[minpos2][j]]--;
			}
			for(int j = 0; j < 3; j++)
				if(numn[zmember[minpos][j]] == 1)
					continue;
				else
					numn[zmember[minpos][j]]--;
			//for(int i = 1; i <= n; i++)
			//	cout << numn[i] << " ";
			//cout << endl;
		}
	}
}

int main()
{
	get();
	work();
	return 0;
}
