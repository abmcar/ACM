
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm> 
using namespace std;
string add(string aa,string bb)
{
	string aaa=aa;
	string bbb=bb;
	if(aa.length()<bb.length())
	{
		aaa=bb;
		bbb=aa;
	}
	long long q,w,qq,ww;
	q=aaa.size();
	w=bbb.size();
	qq=q-1;
	for(ww=w-1;ww>=0;qq--,ww--)
	{
		aaa[qq]+=bbb[ww]-'0';
	}
	for(qq=q-1;qq>=1;qq--)
	{
		if(aaa[qq]>'9')
		{
			aaa[qq]-=10;
			aaa[qq-1]++;
		}
	}
	if(aaa[0]>'9')
	{
		aaa[0]-=10;
		aaa='1'+aaa;
	}
	return aaa;
}
int main()
{
	string s[100005];
	s[1]='1';
	s[2]='3';
	int i,n;
	for(i=3;i<=260;i++)
	{
		s[i]=add(s[i-1],s[i-2]);
	}
	while(~scanf("%d",&n))
	{
	printf("%s\n",s[n].c_str());
	}
	return 0;
}
