#include<iostream>
#include<algorithm>

using namespace std;

int n;
int num[522222];
long long ans;

void msort(int l,int r)
{
    int mid = (l+r)/2;
    if(l == r)
        return;
    msort(l,mid);
    msort(mid+1,r);
    int leftstr = l;
    int rightstr = mid+1;
    int endstr = l;
    int tempnum[522222];
    for(int i = l; i <= r; i++)
        tempnum[i] = num[i];
    while(leftstr <= mid && rightstr <= r)
    {
        if(num[leftstr] > num[rightstr])
        {
            ans += mid-leftstr+1;
            tempnum[endstr++] = num[rightstr];
            rightstr++;
        }else
        {
            tempnum[endstr++] = num[leftstr];
            leftstr++;
        }
    }
    while(leftstr <= mid)
    {
        tempnum[endstr++] = num[leftstr];
        leftstr++;
    }
    while(rightstr <= r)
    {
        tempnum[endstr++] = num[rightstr];
        rightstr++;
    }
    for(int i = l; i <= r; i++)
        num[i] = tempnum[i];
    return;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    msort(1,n);
    cout << ans;
    return 0;
}