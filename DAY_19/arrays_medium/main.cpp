#include <iostream>
#include <vector> 
#include <algorithm>
#include <map>
#include <unordered_map>

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

vector<int> twoSum_better(vector<int> nums, int target)
{
    int n = nums.size(); 
    vector<int> ans;
    map<int,int> preMap; 

    for(int i = 0; i < n; i++)
    {   
        int rem = target - nums[i];

        if(preMap.find(rem) != preMap.end())
        {
            ans.push_back(i);
            ans.push_back(preMap[rem]);
            break;
        }
        preMap[nums[i]] = i;
           
    }

    return ans;
}

void SortArr(vector<int> &nums)
{
    int n = nums.size(); 
    int cnt0 = 0, cnt1 = 0 , cnt2 = 0;

    for(int i = 0; i < n; i++)
    {
        if(nums[i] == 0) cnt0++; 
        else if(nums[i] == 1) cnt1++; 
        else cnt2++;
    }

    for(int i = 0; i < cnt0; i++)
        nums[i] = 0; 
    for(int i = cnt0; i < cnt0 + cnt1; i++)
        nums[i] = 1; 
    for(int i = cnt1 + cnt0; i < n; i++)
        nums[i] = 2;

    for(auto it : nums)
    {
        cout << it << " ";
    }


}

void SortArr_Optimal(vector<int> &nums)
{   
    int n = nums.size();
    int l = {0}; int m = {0}; 
    int h = n - 1;

    while(m <= h)
    {
        if(nums[m] == 0)
        {
            swap(nums[m],nums[l]); 
            l++; 
            m++;
        }
        else if(nums[m] == 1)
        {
            m++;
        }
        else
        {
            h--;
        }
    }

    for(auto it : nums)
    {
        cout << it << " ";
    }


}

int majorityEle(vector<int> nums)
{
    int n = nums.size(); 
    unordered_map<int, int> mpp; 

    for(int i = 0; i < n; i++)
    {   
        mpp[nums[i]] += 1;
        if(mpp[nums[i]] > n / 2) return nums[i];
        
    }

    return -1; 

}

int main()
{
    
    vector<int> a = {3,3,4}; 

    majorityEle(a);

    return 0;
}