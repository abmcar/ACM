    #include<iostream>
    #include<algorithm>
    #include<string>

    using namespace std;

    int k;
    string s;

    int main()
    {
        cin >> s >> k;
        for(int i = 1; i <= k; i++)
        {
            string ans = s;
            ans.erase(ans.begin());
            for(int j = 1; j < s.size(); j++)
            {
                string temp = s;
                temp.erase(temp.begin()+j);
                ans = min(ans,temp);
            }
            s = ans;
        }
        while(s[0] == '0')
            s.erase(s.begin());
        if(s == "")
            cout << 0;
        else
            cout << s;
        return 0;
    }