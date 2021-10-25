#include<iostream>
#include<string>
#include<map>

using namespace std;

map<char,int> m1,m2;
int num[333];
int t,n,k;
int tt;
string s1,s2;

void work()
{

}

int main()
{
    cin >> t;
    for(int ti = 1; ti <= t; ti++)
    {
        cin >> n >> k;
        cin >> s1 >> s2;
        for(int i = 'a'; i <= 'z'; i++)
            m1[i] = m2[i] = 0;
        for(int i = 0; i < n; i++)
            m1[s1[i]]++,m2[s2[i]]++;
        for(int i = 'a'; i <= 'z'; i++)
            num[i] = m1[i]-m2[i];
        bool flag = 1;
        int tempans = 0;
        for(int i = 'a'; i <= 'z'; i++)
            tempans += m1[i];
        if(tempans > 0)
        {
            cout << "No" << endl;
            continue;
        }
        for(int i = 'a'; i <= 'z'; i++)
        {
            if(flag == 0)
                break;
            num[i] = std::abs(num[i]*-1);
            if(num[i] % k != 0)
            {
                cout << "No" << endl;
                flag = 0;
                continue;
            }
        }
        if(flag == 1)
            cout << "Yes" << endl;
    }
    return 0;
}