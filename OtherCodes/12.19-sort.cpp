#include <bits/stdc++.h>

using namespace std;

long long n, k, d;
double peopV;
double ans;

struct Node
{
    int id;
    double v;
    double nowTime;
    double finishTime;
    void getFinishTime()
    {
        double nowDis = d - peopV * nowTime;
        double backTime = nowDis / (peopV + v);
        nowDis = nowDis - backTime * peopV;
        double nextTime = nowDis / v;
        finishTime = nowTime + backTime + nextTime;
        // if (finishTime > d / peopV)
        // finishTime = d / peopV;
    }
    const bool operator<(Node b) const
    {
        return finishTime > b.finishTime;
    }
};

priority_queue<Node> Q;

const long long TIME_H = 3600;
const long long TIME_M = 60;

void print(long long totS)
{
    long long cntH = totS / TIME_H;
    totS = totS % TIME_H;
    long long cntM = totS / TIME_M;
    totS = totS % TIME_M;
    cout << cntH << " " << cntM << " " << totS << endl;
}

int main()
{
    cin >> n >> k >> d;
    cin >> peopV;
    peopV = peopV / 3600;
    for (long long i = 1; i <= k; i++)
    {
        double tempV;
        cin >> tempV;
        tempV = tempV / 3600;
        Node tempNode;
        tempNode.id = i;
        tempNode.v = tempV;
        tempNode.nowTime = d / tempV;
        tempNode.getFinishTime();
        Q.push(tempNode);
        ans = max(ans, d / tempV);
        // print(tempNode.nowTime);
        // print(tempNode.finishTime);
    }
    for (long long i = k * 2 + 1; i <= n; i++)
    {
        Node nowNode = Q.top();
        Q.pop();
        // cout << i << " " << nowNode.id << " " << nowNode.nowTime << " " << nowNode.finishTime << " " << nowNode.v << endl;
        nowNode.nowTime = nowNode.finishTime;
        nowNode.getFinishTime();
        ans = max(nowNode.nowTime, ans);
        Q.push(nowNode);
        // print((long long)nowNode.nowTime);
        // print((long long)nowNode.finishTime);
    }
    // cout << d << endl << peopV << endl;
    // cout << d/peopV << endl;
    // cout << min((long long)d / peopV, (long long)ans) << endl;
    print(min((long long)ans,(long long)(d/peopV)));
    return 0;
}