#include <bits/stdc++.h>
using namespace std;

int subArrayWithXorK(vector<int> &nums , int t)
{
    int cnt = 0; 

    for(int i = 0; i < nums.size(); i++)
    {   
        int XOR = 0;    
        for(int j = i; j < nums.size(); j++)
        {   
            XOR = XOR ^ nums[j];
            if(XOR == t) cnt++; 
        }
    }

    return cnt;
}

int SubArrayWithXorK_OP(vector<int> &nums , int t)
{
    int cnt = 0;
    int xr = 0;
    unordered_map<int , int> prefix; 
    prefix[0] = 1;

    for(int i = 0; i < nums.size(); i++)
    {
        xr = xr ^ nums[i];
        int x = xr ^ t;
        if(prefix.find(x) != prefix.end())
        {
            cnt += prefix[x];
        } 
        else{
            prefix[xr] += 1;
        }
    }
    return cnt;
}


int main()
{
    vector<int> a = {5, 6, 7, 8, 9}; 

    cout << SubArrayWithXorK_OP(a, 5) << endl; 
    return 0;
}