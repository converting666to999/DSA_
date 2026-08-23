#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

vector<int> leadersInArray(vector<int> &nums)
{
        int n = nums.size(); 

        int lead = INT_MIN; 
        vector<int> ans;

        for(int i = n - 1; i >= 0; i--)
        {
            if(nums[i] >= lead)
            {
                ans.push_back(nums[i]);
            }
            lead = max(lead, nums[i]);
        }
        
        reverse(ans.begin(),ans.end());

        return ans;

}

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6}; 

    //fn call
    for(auto it : leadersInArray(arr))
    {
        cout << it << " "; 
    }

    return 0;
}