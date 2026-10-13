#include <bits/stdc++.h>
using namespace std;

void func(int n ,string str , int last , vector<string> &ans)
{
    // base case
    if(str.size() == n)
    {
        ans.push_back(str); 
        return; 
    }
       
    func(n , str + '0' , 0 , ans); 

    if(str.back() == 0)
    {
        func(n , str + '1' , 1 , ans);
    }
}       

vector<string> genBinaryStr(int n)
{
    vector<string> ans;
    func(n , "" , 0 , ans);
    
    return ans; 
}

int main()
{
    
    return 0;
}