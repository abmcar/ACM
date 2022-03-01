#include <bits/stdc++.h>
using namespace std;


struct node {
    node *l, *r;
    int v;
    node(node *tl, node *tr) {
        l = tl;
        r = tr;
        v = __gcd(tl->v, tr->v);
    }
    node(int x) {
        l = r = nullptr;
        v = x;
    }
};


int a[200000];


node* build(int tl, int tr) {
    if (tl == tr - 1) {
        return new node(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        return new node(build(tl, tm), build(tm, tr));
    }
}
 
int query(node *t, int tl, int tr, int l, int r) {
    if(l >= r) return 0;
    if(tl == l && tr == r) return t->v;
    int tm = (tl + tr) / 2;
    int r1 = query(t->l, tl, tm, l, min(r, tm));
    int r2 = query(t->r, tm, tr, max(l, tm), r);
    return __gcd(r1, r2);
}
 
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    node *t = build(0, n);
    
    vector<vector<int>> segs(n);
    for(int i = 0; i < n; i++) {
        int lb = i + 1, ub = n, tans = i;
        while(lb <= ub) {
            int tm = (lb + ub) / 2;
            if(query(t, 0, n, i, tm) >= tm - i) {
                tans = tm;
                lb = tm + 1;
            } else {
                ub = tm - 1;
            }
        }
        if(query(t, 0, n, i, tans) == tans - i) {
            segs[tans - 1].push_back(i);
        }
    }
    
    int ans = 0, pi = -1;
    for(int i = 0; i < n; i++) {
        for(int x: segs[i]) {
            cout << i << " " <<x << endl;
            if(x > pi) {
                ans++;
                pi = i;
            }
        cout << pi << " " << ans << endl;
        }
        // cout << ans << ' ';
    }
}