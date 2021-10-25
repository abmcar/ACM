#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int mod=10000007;
const int N=1e9+10;

ll n,M,arr[15],ans;

struct Matrix{
	ll m[15][15];
	
	Matrix(){
		memset(m,0,sizeof(m));
		for(int i=0;i<=n+1;i++){
			m[i][n+1]=1;
			if(i==n+1) continue;
			m[i][0]=10;
			for(int j=1;j<=i;j++)
				m[i][j]=1;
		}
	}
	
	void clear(){
		memset(m,0,sizeof(m));
		for(int i=0;i<=n+1;i++)
			m[i][i]=1;
	}
	
	void display(){
		cout<<"Matrix's begin:"<<endl;
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;j++)
				if(j<n+1) cout<<m[i][j]<<" ";
				else cout<<m[i][j]<<endl;
		cout<<"Matrix's end:"<<endl;
	}
	
	friend Matrix operator*(Matrix a,Matrix b){
		Matrix ans;
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;j++){
				ans.m[i][j]=0;
				for(int k=0;k<=n+1;k++)
					ans.m[i][j]+=a.m[i][k]*b.m[k][j]%mod;
			}
		return ans;
	}
	
	friend Matrix operator^(Matrix base,ll k){
		Matrix ans;
		ans.clear();
		while(k){
			if(k&1) ans=ans*base;
			base=base*base;
			k>>=1;
		}
		return ans;
	}
	
};

int main(){
//	cout<<"hello"<<endl;
	while(~scanf("%lld%lld",&n,&M)){
		Matrix base;ans=0;
		arr[0]=23;arr[n+1]=3;
		for(int i=1;i<=n;i++){
			scanf("%lld",&arr[i]);
		}
		base=base^M;
//		base.display();
		for(int i=0;i<=n+1;i++){
			ans+=arr[i]*base.m[n][i];
//			cout<<base.m[n][i]<<endl;
		}
		printf("%d\n",ans%mod);
	}
	return 0;
}
/*
	3 1
	1 2 3
	
	23		10 0 0 0 1				233				
	a1		10 1 0 0 1				a1+23*10+3
	a2	*	10 1 1 0 1	^m	=		a2+a1+23*10+3		^(m-1)
	a3		10 1 1 1 1				a3+a2+a1+23*10+3
	3   	        0  0 0 0 1				3
*/