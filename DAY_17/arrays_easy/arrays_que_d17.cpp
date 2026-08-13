#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int maxConsecutive(vector<int> &nums)
{
    int n = nums.size();
    int maxi = {0}; 
    int count = {0}; 

    for(int i = 0; i < n; i++)
    {
        if(nums[i] == 1)
        {
            count++;
        }
        else count = 0;

        maxi = max(maxi,count);
    }

    return maxi;
}

// brute tc O(n^2)
int singleNumber(vector<int> &nums)
{
    int n = nums.size();

    for(int i = 0; i < n; i++)
    {
        int num = nums[i]; 
        int count = 0;

        for(int j = 0; j < n; j++)
        {
            if(nums[j] == num) count++;
        }

        if(count == 1) return num;
    }

    return -1;
}

// tc O(3n) sc(x+1)
int singleNumber_better(vector<int> &nums)
{
    int n = nums.size();
    int maxi = {0}; 

    for(int i = 0; i < n; i++)
    {
        maxi = max(maxi,nums[i]);
    }

    vector<int> hash(maxi + 1, 0); 

    for(int i = 0; i < n; i++)
    {
        hash[nums[i]] += 1;
    }

    for(int i = 0; i < n; i++)
    {
        if(hash[i] == 1) return i;
    }

    return -1;
}

int singleNumber_Optimised(vector<int> &nums)
{
    int n = nums.size(); 
    int xor1 = {0}; 

    for(int i = 0; i < n; i++)
    {
        xor1 = xor1 ^ nums[i];
    }
    return xor1;
}

int longestSubarrayWithK(vector<int> a, long long k)
{
    int n = a.size(); 
    int maxLen = {0};
    map<long long , int> preMap;
    long long sum = {0}; 

    for(int i = 0; i < n; i++)
    {
        sum += a[i];
        if(sum == k)
            maxLen = max(maxLen, i + 1); 
        
        int rem = sum - k; 
        if(preMap.find(rem) != preMap.end())
        {
            int len = i - preMap[rem]; 
            maxLen = max(maxLen,len);
        }
        if(preMap.find(sum) == preMap.end())
            preMap[sum] = i;
    }

    return maxLen;
}

int longestSubarrayWithK_better(vector<int> a, long long k)
{
    int n = a.size();
    int i = 0;
    int j = 0; 
    int maxLen = {0}; 
    long long sum = a[0]; 

    while(j < n)
    {
        while(i <= j && sum > k)
        {
            sum -= a[i];
            i++;
        }
        if(sum == k)
        {
            maxLen = max(maxLen, j - i + 1);
        }
        j++;
        if(j < n)sum += a[j];
    }

    return maxLen;
}

int main()
{
    
    vector<int> nums = {10, 5, 2, 7, 1, 9}; 


    cout << longestSubarrayWithK_better(nums,15);

    

    return 0;
}