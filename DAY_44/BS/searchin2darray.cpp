#include <bits/stdc++.h>
using namespace std;

//better approach
bool findElement(vector<vector<int>> &nums , int target)
{
    int i = 0 , j = nums[0].size() - 1;
    while(i < nums.size() && j >= 0)
    {
        if(nums[i][j] == target)
            return true; 
        else if(nums[i][j] > target)
            j--; 
        else i++; 
    }

    return false; 
}

// optimal sol 
bool findElement(vector<vector<int>> &nums, int target)
{
    int low = 0 , high = (nums.size() * nums[0].size()) - 1; 

    while(low <= high)
    {
        int mid = low + (high - low) / 2; 
        int n = mid / nums[0].size(); 
        int m = mid % nums[0].size();

        if(nums[n][m] == target)
            return true; 
        else if(nums[n][m] > target)
            high = mid - 1; 
        else low = mid + 1;
    }

    return false; 
}

int main()
{
    
    return 0;
}