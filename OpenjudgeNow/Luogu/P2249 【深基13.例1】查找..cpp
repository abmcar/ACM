#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int num[(int)1e6+10];

inline int Search(int number)
{
    int l = 1;
    int r = n;
    int ans = -1;
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(num[mid] >= number)
        {
            if(num[mid] == number)
            ans = mid;
            r = mid;
        }else
            l = mid+1;
        if(l == mid && r == mid)
            break;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    for(int i = 1; i <= m; i++)
    {
        int temp;
        cin >> temp;
        cout << Search(temp) << " ";
    }
    return 0;
}