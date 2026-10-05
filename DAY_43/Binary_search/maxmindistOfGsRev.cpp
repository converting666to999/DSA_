#include <bits/stdc++.h>
using namespace std;

// brute approach

long double maxMindist(vector<int> &nums, int d)
{   
    vector<int> howMny(nums.size() - 1 , 0);
     
    
    for(int i = 1; i <= d; i++)
    {   
        int maxvalue = -1 , maxInd = -1;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            long double diff = nums[i + 1] - nums[i]; 
            long double sectionlen = diff / (long double)(howMny[i] + 1); 
            if(sectionlen > maxvalue)
            {
                maxvalue = sectionlen; 
                maxInd = i; 
            }     
        }
        howMny[maxInd]++;
    }

    long double maxAns = -1; 
    for(int i = 0; i < nums.size() - 1; i++)
    {
        long double diff = nums[i + 1] - nums[i]; 
        long double sectionlen = diff / (long double)(howMny[i] + 1); 
        maxAns = max(maxAns , sectionlen);
    }

    return maxAns;
}

double long minMaxDist_better(vector<int> &nums , int d)
{
    vector<int> howMny(nums.size() - 1 , 0); 
    priority_queue<pair<long double , int>> check; 

    for(int i = 0; i < nums.size() - 1; i++)
        check.push({nums[i + 1] - nums[i] , i});


    for(int i = 1; i <= d; i++)
    {
        auto top = check.top(); check.pop(); 
        int sectionInd = top.second; 
        howMny[sectionInd]++;

        long double iniDiff = nums[sectionInd + 1] - nums[sectionInd]; 
        long double newseclen = iniDiff / (long double)(howMny[sectionInd] + 1); 
        check.push({newseclen , sectionInd});
    }

    return check.top().first; 
}

int main()
{
    vector<int> a = {3, 6, 12, 19, 33}; 

    // fn call 
    cout << minMaxDist_better(a , 3) << endl; 
    return 0;
}