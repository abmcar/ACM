#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<long long>num;
int n;
long long ans;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int m = 0;
        int n = 1000010;
        long long temp;
        cin >> temp;
        if(i == 1)
        {
            num.push_back(temp);
            ans += temp;
            continue;
        }
        int pos = upper_bound(num.begin(),num.end(),temp)-num.begin();
        if(pos - 1 >= 0)
            n = num[pos - 1];
        if(pos < num.size())
            m = num[pos];
        ans += min(::abs(temp-n),::abs(temp-m));
        num.insert(upper_bound(num.begin(),num.end(),temp),temp);
        cout << pos << " " << m << " " << n << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}