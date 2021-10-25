#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define Maxn (int)1e5+10

using namespace std;

int num[Maxn];
vector<int> totnum;
int n,m;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        num[temp]++;
        if(num[temp] == 1)
            totnum.push_back(temp);
    }
    sort(totnum.begin(),totnum.end());
    for(int i = 0; totnum[i]*2 <= m; i++)
    {
        num[totnum[i]]--;
        if(num[m-totnum[i]] > 0)
        {
            cout << totnum[i] << " " << m-totnum[i] << endl;
            return 0;
        }
        num[totnum[i]]++;
    }
    cout << "No Solution" << endl;
    return 0;
}
