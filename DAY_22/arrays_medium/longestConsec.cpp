#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <set>
#include <unordered_set>

using namespace std;

bool ls(vector<int> &arr,int  t)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == t)
            return true;
    }
    return false;
}

int longestConsecutive(vector<int> &nums)
{
    int n = nums.size(); 
    int maxcnt = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        int x = nums[i]; 
        int cnt = 1;

        while(ls(nums, x+1) == true)
        {
            x = x + 1; 
            cnt++;
        }

        maxcnt = max(maxcnt, cnt);
        
    }
    return maxcnt;
}

int longestConsecutive_better(vector<int> &nums)
{
    int n = nums.size(); 
    int cntcurr = 0; 
    int last_smallest = INT_MIN; 
    int longest = 1;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++)
    {
        if(nums[i] - 1 == last_smallest)
        {
            cntcurr++; 
            last_smallest = nums[i];
        }
        else if(nums[i] != last_smallest)
        {
            cntcurr = 1;
            last_smallest = nums[i];
        }

        longest = max(longest, cntcurr);
    }
    
    return longest;

}

int longestConsecutive_Op(vector<int> &nums)
{
    int n = nums.size(); 
    if(n == 0) return 0; 
    unordered_set<int> ans;
    int longest = INT_MIN;

    // store in set
    for(int i = 0; i < n; i++)
    {
        ans.insert(nums[i]); 
    }

    for(auto it : ans)
    {
        if(ans.find(it - 1) == ans.end())
        {
            int x = it; 
            int cnt = 1;

            while(ans.find(x+1) != ans.end())
            {   
                x = x+1;
                cnt++; 

            }
            longest = (longest,cnt);
        }
    }

    return longest;

}

int main()
{
    vector<int> arr = {100,4,200,1,3,2}; 

    cout << longestConsecutive_Op(arr);

    return 0;
}