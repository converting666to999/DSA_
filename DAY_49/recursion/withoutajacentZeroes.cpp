#include <bits/stdc++.h>
using namespace std;

void func(int n , string str , int last , vector<string> &ans)
{
    if(str.size() == n)
    {
        ans.push_back(str); 
        return; 
    }

    func(n , str + '1' , 1 , ans); 

    if(last == 1)
        func(n , str + '0' , 0 , ans);
}

vector<string> genAllBinary(int n)
{
    vector<string> ans; 
    func(n , "" , 1 , ans); 

    return ans;
}

int main()
{
    
    return 0;
}