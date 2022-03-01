#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define int long long

using namespace std;

int n, ans;
vector<int> na, nb;

template <typename T>
class Fenwick
{
public:
    Fenwick(int _n) : n(_n)
    {
        fenw.resize(n + 1);
    }
    void modifty(int x, T val)
    {
        while (x <= n)
        {
            fenw[x] += val;
            x = x + lowbit(x);
        }
    }

    T get(int x)
    {
        T cnt{};
        while (x > 0)
        {
            cnt += fenw[x];
            x = x - lowbit(x);
        }
        return cnt;
    }

private:
    vector<T> fenw;
    int n;
    T lowbit(T x)
    {
        return x & (-x);
    }
};

signed main()
{
    unordered_map<int, int> pos;
    cin >> n;
    na.resize(n + 1);
    nb.resize(n + 1);
    Fenwick<int> fen(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> na[i];
        pos[na[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        cin >> nb[i];
    for (int i = 1; i <= n; i++)
    {
        if (pos[nb[i]] + fen.get(pos[nb[i]]) == i)
            continue;
        fen.modifty(1, 1);
        fen.modifty(pos[nb[i]], -1);
        ans++;
    }
    cout << ans << endl;
    return 0;
}