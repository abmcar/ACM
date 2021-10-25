#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> Ans;

int cal(vector<int> nowV)
{
    int temp = 0;
    for (int i = 0; i < nowV.size(); i++)
    {
        if (nowV[i] == nowV.size())
        {
            temp += nowV.size()/2;
            continue;
        }
        for (int k = 1; k < nowV.size(); k++)
        {
            int p1 = i - k;
            int p2 = i + k;
            while (p1 < 0)
                p1 += nowV.size();
            while (p2 >= nowV.size())
                p2 -= nowV.size();
            if (nowV[p1] > nowV[i])
            {
                temp += k;
                break;
            }
            if (nowV[p2] > nowV[i])
            {
                temp += k;
                break;
            }
        }
    }
    return temp;
}

void work(int num)
{
    vector<int> V;
    for (int i = 1; i <= num; i++)
        V.push_back(i);
    int nowMax = 0;
    do
    {
        if (cal(V) > nowMax)
        {
            nowMax = cal(V);
            Ans = V;
        }
        if (V[0] != 1 && V[V.size()-1] != V.size())
            break;
    } while (next_permutation(V.begin(),V.end()));
    cout << num << " " << nowMax << endl;
    for (int i = 0; i < Ans.size(); i++)
        cout << Ans[i] << " ";
    cout << endl;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        work(i);
    return 0;
}

/*
1 2 3 4  5  6  7  8  9  10 11  12
1 2 3 6  7  10 12 16 17 20 22  26
  1 1 3  1  3  2  4  1  3  2   4
1 3 6 12 19 29 41 57 74 94 116 132
*/