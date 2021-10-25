#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int t;
int cnt;

// bool check(String oriWord, String ans, String oriString)
// {
//     map<char,bool> MM;
//     String tempString = "";
//     int cnt = 0;
//     for (int i = 0; i < ans.size(); i++)
//     {
//         for (int j = 0; j < oriWord.size(); j++)
//         {
//             // cout << oriWord[j] << " " << MM[oriWord[j]] << " " << j << endl;
//             if (MM[oriWord[j]] == 1)
//                 continue;
//             else
//             {
//                 tempString = tempString + oriWord[j];
//                 if (oriString[cnt++] != oriWord[j])
//                     return false;
//             }
//             // cout << oriWord[j] << " " << MM[oriWord[j]] << " " << j << endl;
            
//         }
//         MM[ans[i]] = true;
//     }
//     // cout << MM.size() << endl;
//     // cout << oriWord << " " << tempString << " "  << oriString << endl;
//     if (tempString == oriString)
//         return true;
//     return false;
// }

bool check (string s,string s1,string s2)
{
    unordered_map<int,int> vis;
    string s3;
    int len1 = s1.length();
    int len2 = s2.length();
    s3 += s1;
    for(int i = 0;i < len2;i++)
    {
        vis[s2[i]- 'a'] = 1;   
        for (int  j= 0; j < len1;j++)
        {
            if (vis[s1[j]-'a'] == 0)
            {
                s3 += s1[j];
            }
        }
    }
    if (s == s3) return true;
    else return false;
}

void work()
{
    unordered_map<char,int> M;
    unordered_map<char,int> oriWord;
    unordered_map<int,char> aftAns;
    // char aftAns[Maxn];
    cnt = 0;
    String string, ans, word, oriString;
    cin >> string;
    oriString = string;
    for (char i : string)
    {
        if (M[i] == 0)
            cnt++;
        M[i]++;
    }
    int tempCnt = 0;
    unordered_map<char,int> tempM;
    for (int i = string.size()-1; i >= 0; i--)
    {
        if (tempM[string[i]] == 0)
            aftAns[++tempCnt] = string[i];
        tempM[string[i]]++;
    }
    bool ok = true;
    int nowNum = 0;
    int nowTot = 0;
    for (int i = 1; i <= M.size(); i++)
    {
        if (M[aftAns[i]] % (cnt - i + 1) != 0)
            ok = false;
        oriWord[aftAns[i]] = M[aftAns[i]] / (cnt - i + 1);
        ans = ans + aftAns[i];
        nowNum = nowNum + M[aftAns[i]];
        nowTot = nowTot + oriWord[aftAns[i]] * (cnt - i + 1);
    }
    // cout << nowTot << endl;
    if (nowTot != string.size())
        ok = false;
    word = "";
    int len = 0;
    for (auto it : oriWord)
        len = len + it.second;
    // cout << len << endl;
    for (int i = 0; i < len; i++)
        word = word + string[i];
    reverse(ans.begin(),ans.end());
    if (!check(oriString,word,ans))
        ok = false;
    if (ok)
        cout << word << " " << ans << endl;
    else
        cout << -1 << endl;
}

int main()
{
    // Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}