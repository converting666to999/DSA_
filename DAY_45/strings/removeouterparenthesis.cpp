#include <bits/stdc++.h>
using namespace std;

string removeOuterParen(string &s)
{
    int cnt = 0; 
    string ans; 

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            if(cnt > 0)
                ans += s[i]; 
            
            cnt++;
        }
        else{
            cnt--; 

            if(cnt > 0)
                ans += s[i];
        }
    }

    return ans; 
}

int main()
{
    string a = "(()())(())"; 

    // fn call 
    cout << removeOuterParen(a) << endl; 
    return 0;
}