#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s , int i , int ind)
{
    while(i < ind)
    {
        if(s[i] != s[ind])
            return false; 
        
        i++; 
        ind--;
    }
    return true; 
}

void func(int ind , string s , vector<string> &current , vector<vector<string>> &ans)
{

    // base case 
    if(ind == s.size())
    {
        ans.push_back(current); 
        return;
    }

    for(int i = ind; i < s.size(); i++)
    {
        if(isPalindrome(s , ind , i) == true)
        {
            current.push_back(s.substr(ind , i - ind + 1)); 
            func(i + 1 , s , current , ans); 
            current.pop_back();
        }
    }
}

vector<vector<string>> part(string s)
{
    vector<vector<string>> ans; 
    vector<string> current;

    // fn call 
    func(0 , s , current , ans); 
    return ans;
}

int main()
{
    
    return 0;
}