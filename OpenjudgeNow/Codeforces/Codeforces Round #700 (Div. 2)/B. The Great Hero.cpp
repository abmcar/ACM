#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

const int Maxn = 1e5+10;
const ll Mod = 1e9+7;
int t,n;
ll heroHealth,heroAttack;
ll totDamage,maxAttack;
struct Monster
{
    ll health,attack;
    ll getDamage()
    {
        return ((health+heroAttack-1)/heroAttack)*attack;
    }
}monster[Maxn];

void work()
{
    totDamage = maxAttack = 0;
    cin >> heroAttack >> heroHealth;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> monster[i].attack;
    for(int i = 1; i <= n; i++)
    {
        cin >> monster[i].health;
        totDamage += monster[i].getDamage();
        maxAttack = max(maxAttack,monster[i].attack);
    }
    if(heroHealth >= (totDamage - maxAttack))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> t;
    while(t--)
        work();
    return 0;
}