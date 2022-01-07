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
#include <fstream>

#define Buff std::ios::sync_with_stdio(false), fin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

string oriString = "";
vector<string> totS;
map<string, int> M;

struct Node
{
    string s;
    int val;
    bool operator<(Node b) const
    {
        return val > b.val;
    }
    bool operator>(Node b) const
    {
        return val < b.val;
    }
    bool operator<=(Node b) const
    {
        return val >= b.val;
    }
};
vector<Node> vN;
Node tmp[Maxn];

// 归并排序
void merge_sort(vector<Node> &q, int l, int r)
{
    if (l >= r)
        return;

    int mid = l + r >> 1;

    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

// 快速排序
void quick_sort(vector<Node> &q, int l, int r)
{
    if (l >= r)
        return;

    int i = l - 1, j = r + 1;
    Node x = q[l + r >> 1];
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
        {
            Node temp = q[i];
            q[i] = q[j];
            q[j] = temp;
            // swap(q[i], q[j]);
        }
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

// 输出和分割字符串
void init()
{
    string inputFile = "";
    cout << "输入文件名" << endl;
    cin >> inputFile;
    fstream fin(inputFile);
    // freopen(inputFile.c_str(), "r", stdin);
    string temp;
    while (fin >> temp)
    {
        if (temp == "###")
            break;
        oriString = oriString + temp;
    }
    for (int i = 0; i < oriString.size() - 5; i++)
    {
        string nowString = oriString.substr(i, 4);
        // if (nowString.find(",") != string::npos)
        //     continue;
        // if (nowString.find(":") != string::npos)
        //     continue;
        // if (nowString.find(",") != string::npos)
        //     continue;
        if (M[nowString] == 0)
            totS.push_back(nowString);
        M[nowString]++;
    }
    for (string it : totS)
        vN.push_back({it, M[it]});
}

signed main()
{
    // Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    init();
    int nowTime = clock();
    merge_sort(vN, 0, vN.size() - 1);
    cout << "归并排序前100结果" << endl;
    for (int i = 0; i < min(100, (int)vN.size()); i++)
        cout << vN[i].s << " " << vN[i].val << endl;
    cout << "归并排序所用时间:" << clock() - nowTime << endl;

    nowTime = clock();
    cout << "快速排序前100结果" << endl;
    quick_sort(vN, 0, vN.size() - 1);
    for (int i = 0; i < min(100, (int)vN.size()); i++)
        cout << vN[i].s << " " << vN[i].val << endl;
    cout << "快速排序所用时间:" << clock() - nowTime << endl;
    return 0;
}