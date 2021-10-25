#include<iostream>
#include<algorithm>

#define Maxn (int)1e6

using namespace std;

int n,m;
long long a[Maxn],b[Maxn];
int ans;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i=  1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for(int i=  1; i <= m; i++)
        cin >> b[i];
    int posa,posb;
    posa = posb = 1;
    long long tempa = a[1];
    long long tempb = b[1];
    while(posa <= n && posb <= m)
    {
        if(tempb == tempa)
        {
            ans++;
            if((posa == n) == (posb == m))
            {
                if(posa != n)
                {
                    posa++;
                    posb++;
                    tempa = a[posa];
                    tempb = b[posb];
                    continue;
                }
                break;
            }
            else
            {
                cout << "-1";
                return 0;
            }
        }
        if(tempa > tempb)
        {
            if(posb == m)
            {
                cout << "-1";
                return 0;
            }
            posb++;
            tempb += b[posb];
            continue;
        }else
        {
            if(posa == n)
            {
                cout << "-1";
                return 0;
            }
            posa++;
            tempa += a[posa];
            continue;
        }
    }
    cout << ans;
    return 0;
}