#include <bits/stdc++.h>
using namespace std;

void func(int ind , string s , string temp , vector<string> &ans , unordered_map<char , string> &mp)
{
    // base case 
    if(ind >= s.size())
    {
        ans.push_back(temp); 
        return;
    }

    // fetch the string bound to digit
    char ch = s[ind];
    string str = mp[ch];

    for(int i = 0; i < str.size(); i++)
    {   
        // do
        temp.push_back(str[i]);
        // explore
        func(ind + 1 , s , temp , ans , mp);
        // return 
        temp.pop_back();
    }
}   

vector<string> letterCombinations(string digits) 
{
    if(digits.size() == 0)
        return {}; 
        
    vector<string> ans;
    string temp = "";
    unordered_map<char , string> mp; 

    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    func(0 , digits , temp , ans , mp);

    return ans;
}

int main()
{
    
    return 0;
}