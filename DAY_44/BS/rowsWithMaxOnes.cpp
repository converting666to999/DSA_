#include <bits/stdc++.h>
using namespace std;

// brute force

// basically lowerbound
int cntoffones(vector<int> &nums , int target)
{   
    sort(nums.begin() , nums.end()); 
    
    int low = 0 , high = nums.size() - 1; 
    int ans = nums.size();

    while(low <= high)
    {
        int mid = low + (high - low) / 2; 
        if(nums[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans; 
}

vector<int> rowWithMaxOnes(vector<vector<int>> &mat)
{
    int ind = -1;
    int maxvalue = -1;
    vector<int> ans; 

    for(int i = 0; i < mat.size(); i++)
    {
        int cnt = mat[i].size() - cntoffones(mat[i] , 1);
        if(cnt > maxvalue)
        {
            maxvalue = cnt; 
            ind = i; 
        }
        
    }

    ans.push_back(ind); 
    ans.push_back(maxvalue);

    return ans; 
}   

int main()
{
    
    return 0;
}