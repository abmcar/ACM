#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>

using namespace std;

int n;
long long nowmid;
long long ta,tb;
long long lminn = 0;
long long lmaxn = 9999999999;

int main()
{
	cin >> n;
	for(int i = 1; i <= (n+1)/2; i++)
	{
		cin >> ta;
		if(i == 1)
		{
			nowmid = ta;
			cout << nowmid << endl;
			continue;			
		}
		cin >> tb;
		long long tmin = min(ta,tb);
		long long tmax = max(ta,tb);
		if(tmin >= nowmid)
		{
			lminn = nowmid;
			nowmid = min(lmaxn,tmin);
			if(nowmid == lmaxn)
				lmaxn = tmin;
			else
			{
				if(tmin == lmaxn)
					lmaxn = min(tmin,lmaxn);
				lmaxn = min(lmaxn,tmax);
			}

			cout << lminn << " " << lmaxn << " " << nowmid << endl;
			continue;
		}
		if(tmax <= nowmid)
		{
			lmaxn = nowmid;
			nowmid = max(lminn,tmax);
			if(nowmid == lminn)
				lminn = tmax;
			else
				lminn = max(lminn,tmin);
			cout << lminn << " " << lmaxn << " " << nowmid << endl;
			continue;
		}
		lmaxn = min(tmax,lmaxn);
		lminn = max(tmin,lminn);
		cout << lminn << " " << lmaxn << " " << nowmid << endl;
	}
	return 0;
}
