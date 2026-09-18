#include <bits/stdc++.h>
using namespace std;

vector<int> FindErrorNums(vector<int> &nums)
{
    vector<int> hashArr(nums.size()+1); 
    vector<int> ans;

    //creating hashArr
    for(int i = 0; i < nums.size(); i++)
    {
        hashArr[nums[i]]++;
    }

    for(int i = 0; i < hashArr.size(); i++)
    {
        if(hashArr[i] == 2 || hashArr[i] == 0)
            ans.push_back(i);
    }

    return ans;
}

int main()
{   
    vector<int> a = {1,2,2,4}; 

    for(auto it : FindErrorNums(a))
    {
        cout << it << " ";
    }
    
    return 0;
}