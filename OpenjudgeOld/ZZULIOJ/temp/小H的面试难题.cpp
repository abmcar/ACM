#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n;
priority_queue<int,vector<int>,less<int> > q1;
priority_queue<int,vector<int>,greater<int> > q2;

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	int t;
	cin >> t;
	q1.push(t);
	cout << t << endl;
	for(int i = 2; i <= n; i++)
	{
		int temp;
		cin >> temp;
		int nowk = (i+1)/2;
		if(temp <= q1.top())
			q1.push(temp);
		else
			q2.push(temp);
		while(q1.size() != nowk)
		{
			if(q1.size() > nowk)
			{
				int nowtop = q1.top();
				q2.push(nowtop);
				q1.pop();
			}else
			{
				int nowtop = q2.top();
				q1.push(nowtop);
				q2.pop();
			}
		}
		if((i%2) == 1)
			cout << q1.top() << endl;
	}
	return 0;
}
