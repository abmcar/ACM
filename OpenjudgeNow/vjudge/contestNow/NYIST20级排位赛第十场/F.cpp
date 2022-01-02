#include <iostream>
#include <string>
#include <algorithm>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

String oriString;

int praseInt(String nowString)
{
    while (nowString.size() < 4)
        nowString = '0' + nowString;
    int nowNum = nowString[3] - '0';
    nowNum += (nowString[2] - '0') * 10;
    nowNum += (nowString[1] - '0') * 100;
    nowNum += (nowString[0] - '0') * 1000;
    return nowNum;
}

String toString(int nowNum)
{
    String nowString = "";
    nowString = nowString + (char)(nowNum % 10 + '0');
    nowNum = nowNum / 10;
    nowString = nowString + (char)(nowNum % 10 + '0');
    nowNum = nowNum / 10;
    nowString = nowString + (char)(nowNum % 10 + '0');
    nowNum = nowNum / 10;
    nowString = nowString + (char)(nowNum % 10 + '0');
    reverse(nowString.begin(), nowString.end());
    while (nowString[0] == '0')
        nowString.erase(0, 1);
    return nowString;
}
bool flag = true;

void work()
{
    if (flag)
        flag = false;
    else
        cout << endl;
    cout << "N=" << oriString << ":" << endl;
    if (oriString == "6174")
    {
        cout << "Ok!! 0 times";
        return;
    }
    sort(oriString.begin(), oriString.end());
    if (oriString[0] == oriString[3])
    {
        cout << "No!!";
        return;
    }
    int cnt = 0;
    String nowMin = oriString;
    String nowMax = oriString;
    reverse(nowMax.begin(), nowMax.end());
    while (1)
    {
        int ans = praseInt(nowMax) - praseInt(nowMin);
        cout << praseInt(nowMax) << "-" << praseInt(nowMin) << "=" << ans << endl;
        cnt++;
        if (ans == 0 || ans == 6174)
            break;
        nowMin = toString(ans);
        sort(nowMin.begin(), nowMin.end());
        nowMax = nowMin;
        reverse(nowMax.begin(), nowMax.end());
    }
    cout << "Ok!! " << cnt << " times";
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int temp;
    while (1)
    // for (int i = 1000; i <= 9999; i++)
    {
        cin >> temp;
        if (temp == -1)
            break;
        oriString = toString(temp);
        // cin >> oriString;
        // oriString = toString(i);
        // if (oriString == "-1")
        //     break;
        work();
    }
    return 0;
}

/* 
N=5364:
6543-3456=3087
8730-378=8352
8532-2358=6174
Ok!! 3 times
N=2221:
2221-1222=999
999-999=0
Ok!! 2 times
N=4444:
No!!

 */