#include <iostream>

using namespace std;

int k, x, y;
int n = 1;
/*
xmid = (xmin+xmax+1)/2;
ymid = (ymin+ymax+1)/2;
*/
void work(int xmin, int ymin, int xmax, int ymax, int sx, int sy)
{
    if (xmax - xmin == 1 && ymax - ymin == 1)
    {
        if (sx == xmin && sy == ymin)
            cout << xmax << " " << ymax << " 1" << endl;
        if (sx == xmin && sy == ymax)
            cout << xmax << " " << ymin << " 2" << endl;
        if (sx == xmax && sy == ymin)
            cout << xmin << " " << ymax << " 3" << endl;
        if (sx == xmax && sy == ymax)
            cout << xmin << " " << ymin << " 4" << endl;
        return;
    }
    int xmid = (xmax-xmin+1)/2 + xmin-1;
    int ymid = (ymax-ymin+1)/2 + ymin-1;
    if (sx <= xmid && sy <= ymid)
    {
        cout << xmid+1 << " " << ymid+1 << " 1" << endl;
        work(xmin, ymin, xmid, ymid, sx, sy);
        work(xmid + 1, ymin, xmax, ymid, xmid + 1, ymid);
        work(xmid + 1, ymid + 1, xmax, ymax, xmid + 1, ymid + 1);
        work(xmin, ymid + 1, xmid, ymax, xmid, ymid + 1);
    }
    if (sx <= xmid && sy > ymid)
    {
        cout << xmid + 1 << " " << ymid << " 2" << endl;
        work(xmin, ymid + 1, xmid, ymax, sx, sy);
        work(xmin, ymin, xmid, ymid, xmid, ymid);
        work(xmid + 1, ymin, xmax, ymid, xmid + 1, ymid);
        work(xmid + 1, ymid + 1, xmax, ymax, xmid + 1, ymid + 1);
    }
    if (sx > xmid && sy <= ymid)
    {
        cout << xmid << " " << ymid + 1 << " 3" << endl;
        work(xmid + 1, ymin, xmax, ymid, sx, sy);
        work(xmid + 1, ymid + 1, xmax, ymax, xmid + 1, ymid + 1);
        work(xmin, ymin, xmid, ymid, xmid, ymid);
        work(xmin, ymid + 1, xmid, ymax, xmid, ymid + 1);
    }
    if (sx > xmid && sy > ymid)
    {
        cout << xmid << " " << ymid << " 4" << endl;
        work(xmid + 1, ymid + 1, xmax, ymax, sx, sy);
        work(xmin, ymin, xmid, ymid, xmid, ymid);
        work(xmin, ymid + 1, xmid, ymax, xmid, ymid + 1);
        work(xmid + 1, ymin, xmax, ymid, xmid + 1, ymid);
    }
}

int main()
{
    cin >> k >> x >> y;
    for (int i = 1; i <= k; i++)
        n *= 2;
    work(1,1,n,n,x,y);
    return 0;
}