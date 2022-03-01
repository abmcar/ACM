#include <bits/stdc++.h>
using namespace std;
struct Point
{
    double x, y;
};
Point rotate(Point a, Point p, double angle)
{
    Point v = a ;
    double c = cos(angle), s = sin(angle);
    return Point{p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c};
}
int main()
{
    Point a;
    cin >> a.x >> a.y;
    Point p;
    cin >> p.x >> p.y;
    // double angle;
    // cin >> angle;
    Point b = rotate(a, p, 3.14);
    cout << b.x << ' ' << b.y;
}
