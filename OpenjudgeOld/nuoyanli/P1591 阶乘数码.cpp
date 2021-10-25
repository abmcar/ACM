#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int numa[10010];
int numb[10010];
int ansnum[10010];
int n;
int nownum;
string ans = "1";
string jc[10000];

string getstring(int nn)
{
	string tempstring = "";
	char tempchar = (nn%10)+'0';
	tempstring = tempchar;
	nn /= 10;
	if(nn == 0)
		return tempstring;
	tempchar = nn+'0';
	tempstring = tempchar + tempstring;
	return tempstring;
}

string cul(string stringa, string stringb)
{
	nownum++;
	int lena = stringa.size();
	int lenb = stringb.size();
	for(int i = 0; i <= lena+lenb+100; i++)
		ansnum[i] = 0;
	string stringans = "";
	int lenans;
	for(int i = 0; i < lena; i++)
		numa[i] = stringa[i] - '0';
	for(int i = 0; i < lenb; i++)
		numb[i] = stringb[i] - '0';
	reverse(numa,numa+lena);
	reverse(numb,numb+lenb);
	for(int i = 0; i < lena; i++)
	for(int j = 0; j < lenb; j++)
		ansnum[i+j] += numa[i] * numb[j];
	for(int i = 0; i <= lena+lenb; i++)
	{
		ansnum[i+1] += ansnum[i]/10;
		ansnum[i] = ansnum[i]%10;
	}
	for(int i = lena+lenb+10; i >= 0; i--)
		if(ansnum[i] != 0)
		{
			lenans = i;
			break;
		}
	for(int i = 0; i <= lenans; i++)
	{
		char tempchar = ansnum[i] + '0';
		stringans = tempchar + stringans;
	}
	jc[nownum] = stringans;
	return stringans;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int ta,tb;
		cin >> ta >> tb;
		ans = "1";
		int tempans = 0;
		int tempchar = tb+'0';
		for(int j = 1; j <= ta; j++)
		ans = cul(ans,getstring(j));
		for(int j = 0; j < ans.size(); j++)
			if(ans[j] == tempchar)
				tempans++;
		cout << tempans << endl;
	}
    return 0;
    
}
