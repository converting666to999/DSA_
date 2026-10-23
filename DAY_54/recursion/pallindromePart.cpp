#include <bits/stdc++.h>
using namespace std;

bool isPalin(int left , int right , string &s)
{
    while(left < right)
    {
        if(s[left] != s[right])
            return false; 
        left++; 
        right--;
    }

    return true;
}

void func(int ind , string &s , vector<string> &curr , vector<vector<string>> &ans)
{
    // base case 
    if(ind == s.size())
    {
        ans.push_back(curr); 
        return;
    }

    for(int i = ind; i < s.size(); i++)
    {   
        if(isPalin(ind , i , s) == true)
        {
            string str = s.substr(ind , i - ind + 1); 
            curr.push_back(str); 
            // explore
            func(i + 1 , s , curr , ans); 
            curr.pop_back();
        }
    }
}

vector<vector<string>> part(string s)
{
    vector<vector<string>> ans; 
    vector<string> curr; 

    // fn call
    func(0 , s , curr , ans); 
    return ans;


}

int main()
{
    
    return 0;
}