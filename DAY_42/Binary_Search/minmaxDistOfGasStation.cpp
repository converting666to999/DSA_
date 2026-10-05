#include <bits/stdc++.h>
using namespace std;

double long minMaxDist(vector<int> &nums , int k)
{
    vector<int> howMany(nums.size() - 1, 0); 
    

    for(int i = 1; i <= k; i++)
    {   
        long double maxvalue = -1 , maxInd = -1;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            long double diff = nums[i + 1] - nums[i]; 
            long double sectionlen = diff / (long double)(howMany[i] + 1);
            if(sectionlen > maxvalue)
            {
                maxvalue = sectionlen; 
                maxInd = i;
            }
            howMany[maxInd]++;
            
        }
        
    }

    long double maxAns = -1; 
    for(int i = 0; i < nums.size() - 1; i++)
    {
        long double diff = nums[i + 1] - nums[i]; 
        long double sectionlen = diff / (long double)(howMany[i] + 1); 
        maxAns = max(maxAns , sectionlen); 
    }
    
    return maxAns; 
}

int main()
{
    vector<int> a = {3, 6, 12, 19, 33}; 
    
    // fn call 
    cout << minMaxDist(a , 3) << endl; 
    return 0;
}