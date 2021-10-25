#include<iostream>
#include<string>

using namespace std;

string tempin[2666];
int tot1,tot2;
int stringnum;

int main()
{
    while(cin >> tempin[++stringnum])
    for(int i = 0; i < tempin[stringnum].size(); i++)
        if(tempin[stringnum][i] == 'E')
            break;
    for(int i = 1; i <= stringnum; i++)
    for(int j = 0; j < tempin[i].size(); j++)
    {
        if(tempin[i][j] == 'W')
            tot1++;
        if(tempin[i][j] == 'L')
            tot2++;
        if(tot1 >= 11 || tot2 >= 11)
        {
            if(::abs(tot1-tot2) >= 2)
            {
                cout << tot1 << ":" << tot2 << endl;
                tot1 = 0;
                tot2 = 0;
                continue;
            }
        }
        if(tempin[i][j] == 'E')
        {
            cout << tot1 << ":" << tot2 << endl; 
            break;
        }
    }
    tot1 = tot2 = 0;
    cout << endl;
    for(int i = 1; i <= stringnum; i++)
    for(int j = 0; j < tempin[i].size(); j++)
    {
        if(tempin[i][j] == 'W')
            tot1++;
        if(tempin[i][j] == 'L')
            tot2++;
        if(tot1 >= 21 || tot2 >= 21)
        {
            if(::abs(tot1-tot2) >= 2)
            {
                cout << tot1 << ":" << tot2 << endl;
                tot1 = 0;
                tot2 = 0;
                continue;
            }
        }
        if(tempin[i][j] == 'E')
        {
            cout << tot1 << ":" << tot2 << endl; 
            break;
        }
    }
    return 0;
}