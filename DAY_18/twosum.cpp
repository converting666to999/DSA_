#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int> nums, int target)
{
    int n = nums.size();
    vector<int> ans;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(nums[i] + nums[j] == target)
                ans.push_back(i); 
                ans.push_back(j);
                return ans;

        }
    }

    return ans; 
}

int main()
{
    
    vector<int> a = {3,2,4}; 

    for(auto it : twoSum(a,6) )
    {
        cout << it << " ";
    }


    return 0;
}