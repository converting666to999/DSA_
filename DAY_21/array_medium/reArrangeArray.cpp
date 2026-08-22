#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;


vector<int> reArrange(vector<int> &nums)
{   
    //optimal sol
    int n = nums.size(); 
    vector<int> ans(n, 0);
    int posIndex = {0}; 
    int negIndex = 1;

    for(int i = 0; i < n; i++){
        if(nums[i] > 0)
        {
            ans[posIndex] = nums[i]; 
            posIndex += 2;
        }
          
        else 
        {
            ans[negIndex] = nums[i]; 
            negIndex += 2;
        } 
    }

    // for(int i = 0; i < n/2; i++)
    // {
    //     nums[i * 2] = pos[i];
    //     nums[i * 2 + 1] = neg[i];
    // }

    return ans;

}

int main()
{
    vector<int> a = {3,1,-2,-5,2,-4}; 

    // fn call
    for(auto it : reArrange(a))
    {
        cout << it << " ";
    }

    return 0;
}