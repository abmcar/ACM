#include<iostream>
#include<algorithm>

using namespace std;

int n;
int nnum[10000110];
int num[100000110];
int ans[100000110];
int pos;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		if(nnum[temp] != 0)
			nnum[temp]++;
		else
		{
			pos++;
			num[pos] = temp;
			nnum[temp] = 1;
		}
	}
	sort(num+1,num+1+pos);
	for(int i = 1; i <= pos; i++)
	{
		for(int j = 1; num[j] < num[i]; j++)
			if(num[j] != 0)
			if(num[i] % num[j] == 0)
				ans[i] += nnum[num[j]];
	}
	for(int i = 1; i <= pos; i++)
		cout << num[i] << " " << ans[i]+nnum[i] << endl;
	return 0;
} 
