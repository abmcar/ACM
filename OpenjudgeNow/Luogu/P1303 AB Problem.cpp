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
string jc[100];

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
	if(stringa == "0" || stringb == "0")
		return "0";
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

string jia(string a,string b)
{
	int maxlen = max(a.size(),b.size());
	int lena = a.size();
	int lenb = b.size();
	for(int i = 0; i < maxlen+100; i++)
	{
		numa[i] = 0;
		numb[i] = 0;
		ansnum[i] = 0;
	}
	for(int i = 0; i < lena; i++)
		numa[i] = a[i] - '0';
	for(int i = 0; i < lenb; i++)
		numb[i] = b[i] - '0';
	reverse(numa,numa+lena);
	reverse(numb,numb+lenb);
	for(int i = 0; i <= maxlen; i++)
	{
		ansnum[i] += numa[i]	+ numb[i];
		ansnum[i+1] += (ansnum[i])/10;
		ansnum[i] = ansnum[i]%10;
	}
	int lenans;
	string stringans = "";
	for(int i = maxlen+10; i >= 0; i--)
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
	//cout << stringans << endl;
	return stringans;
}

int main()
{
	string tempa,tempb;
	cin >> tempa >> tempb;
		ans = cul(tempa,tempb);
	cout << ans << endl;
    return 0;
    
}
