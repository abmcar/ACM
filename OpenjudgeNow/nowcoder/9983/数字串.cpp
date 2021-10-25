#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#define ll long long

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
string origins;
map<string,string> s;
vector<string> vs;
bool ischanged;

void prework()
{
    s["k"] = "aa";
    s["l"] = "ab";
    s["m"] = "ac";
    s["n"] = "ad";
    s["o"] = "ae";
    s["p"] = "af";
    s["q"] = "ag";
    s["r"] = "ah";
    s["s"] = "ai";
    s["u"] = "ba";
    s["v"] = "bb";
    s["w"] = "bc";
    s["x"] = "bd";
    s["y"] = "be";
    s["z"] = "bf";

    s["aa"] = "k";
    s["ab"] = "l";
    s["ac"] = "m";
    s["ad"] = "n";
    s["ae"] = "o";
    s["af"] = "p";
    s["ag"] = "q";
    s["ah"] = "r";
    s["ai"] = "s";
    s["ba"] = "u";
    s["bb"] = "v";
    s["bc"] = "w";
    s["bd"] = "x";
    s["be"] = "y";
    s["bf"] = "z";
    
    vs.push_back("k");
    vs.push_back("l");
    vs.push_back("m");
    vs.push_back("n");
    vs.push_back("o");
    vs.push_back("p");
    vs.push_back("q");
    vs.push_back("r");
    vs.push_back("s");
    vs.push_back("u");
    vs.push_back("v");
    vs.push_back("w");
    vs.push_back("x");
    vs.push_back("y");
    vs.push_back("z");

    vs.push_back("aa");
    vs.push_back("ab");
    vs.push_back("ac");
    vs.push_back("ad");
    vs.push_back("ae");
    vs.push_back("af");
    vs.push_back("ag");
    vs.push_back("ah");
    vs.push_back("ai");
    vs.push_back("ba");
    vs.push_back("bb");
    vs.push_back("bc");
    vs.push_back("bd");
    vs.push_back("be");
    vs.push_back("bf");
}

int main()
{
    std::ios::sync_with_stdio(false);
    prework();
    cin >> origins;
    for(int i = 0; i < vs.size(); i++)
        if(origins.find(vs[i]) != -1)
        {
            int pos = origins.find(vs[i]);
            origins.erase(pos,vs[i].size());
            origins.insert(pos,s[vs[i]]);
            cout << origins << endl;
            return 0;
        }
    cout << "-1";
    return 0;
}