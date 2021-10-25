#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

struct node
{
    int x,y,z;
    void get()
    {
        cin >> x >> y >> z;
    }
}N[63333];

node last[63333];
int n;
double ans;

double dis(node a,node b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx*dx+dy*dy+dz*dz);
}

bool cmp(node a,node b)
{
    if(a.z != b.z)
        return a.z < b.z;
    if(dis(a,last[a.z]) < dis(b,last[b.z]))
        last[a.z] = a;
    else
        last[a.z] = b;
    return dis(a,last[a.z]) < dis(b,last[b.z]);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        N[i].get();
    sort(N+1,N+1+n,cmp);
    for(int i = 2; i <= n; i++)
        ans+=dis(N[i-1],N[i]);
    cout << fixed << setprecision(3) << ans;
    return 0;
}