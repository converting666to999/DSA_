#include <bits/stdc++.h>
using namespace std;

int maxDepth(string &s)
{
    int cnt = 0 , maxCnt = INT_MIN; 

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            cnt++; 
        else if(s[i] == ')')
            cnt--; 
        else {
            continue;
        }

        maxCnt = max(maxCnt , cnt);
    }

    return maxCnt; 
}

int main()
{
    
    return 0;
}