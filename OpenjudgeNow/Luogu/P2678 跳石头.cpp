    #include<iostream>
    #include<algorithm>

    using namespace std;

    long long l;
    int n,m;
    long long dis[50100];

    bool check(long long num)
    {
        int cut = 0;
        long long nowdis = 0;
        for(int i = 1; i <= n; i++)
        {
            if(dis[i]-num < nowdis)
                cut++;
            else
                nowdis = dis[i];
        }
        return (cut <= m);
    }

    int main()
    {
        cin >> l >> n >> m;
        for(int i = 1; i <= n; i++)
            cin >> dis[i];
        // dis[n+1] = l;
        long long tl = 1;
        long long tr = l;
        long long ans = 1;
        while(tl <= tr)
        {
            // cout << l << " " << r << endl;
            long long mid = (tl+tr)/2;
            if(check(mid))
            {
                ans = mid;
                tl = mid+1;
            }
            else
                tr = mid-1;
        }
        cout << ans;
        return 0;
    }