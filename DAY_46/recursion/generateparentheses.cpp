#include <bits/stdc++.h>
using namespace std;

void func(vector<string> &ans, int n , int open , int close , string current_str)
{
    // base case
    if(current_str.size() == n * 2)
    {
        ans.push_back(current_str); 
        return;
    }

    if(open < n) func(ans , n , open+1 , close , current_str+'(');
    if(close < open) func(ans , n , open , close+1 , current_str+')'); 
}   

vector<string> genParen(int n)
{
    vector<string> ans; 
    func(ans , n , 0 , 0 , "");
    return ans; 
}

int main()
{   
    for(auto it : genParen(3))
        cout << it << " "; 
    return 0;
}