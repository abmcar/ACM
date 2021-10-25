#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int ans;
int maxn;
int str[10010];
int fin[10010];
int now[10010];
vector<int> strt[10010];

void get()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> str[i] >> fin[i];
	return;
}

void dfs(int t, int nowans)
{
	if(t >= maxn)
		return;
	if(now[t] > nowans)
		return;
	//cout << t << "  " << nowans << endl;
	now[t] = nowans;
	ans = max(ans,nowans);
	for(int i = 0; i < strt[t].size(); i++)
	{
		if(now[strt[t][i]] > nowans)
			continue;
		dfs(strt[t][i],nowans+1);
		now[strt[t][i]] = nowans+1;
	}
	t++;
	while(strt[t].size() == 0)
		t++;
	dfs(t,nowans);
}

void work()
{
	for(int i = 1; i <= n; i++)
		maxn = max(maxn,fin[i]);
	maxn += 100;
	for(int i = 1; i <= n; i++)
		strt[str[i]].push_back(fin[i]);
	dfs(1,0);
	cout << ans << endl;
}

int main()
{
	get();
	work();
	return 0;
} 
