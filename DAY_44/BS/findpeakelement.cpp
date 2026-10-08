#include <bits/stdc++.h>
using namespace std;

int findrow(vector<vector<int>> &nums , int mid)
{   
    int maxi = INT_MIN;
    int ind = -1; 
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i][mid] > maxi)
        {
            maxi = nums[i][mid]; 
            ind = i;
        }
    }

    return ind;
}

vector<int> findPeakGrind(vector<vector<int>> &matrix)
{
    int low = 0 , high = matrix[0].size() - 1; 

    while(low <= high)
    {
        int mid = low + (high - low) / 2; 
        int row = findrow(matrix , mid);
        
        int left = mid - 1 >= 0 ? matrix[row][mid - 1] : -1; 
        int right = mid + 1 < matrix[0].size() ? matrix[row][mid + 1] : -1;  
         
        if(matrix[row][mid] > left && matrix[row][mid] > right)
            return {row , mid}; 
        else if(matrix[row][mid] < left)
            high = mid - 1;
        else low = mid + 1;
    }

    return {-1 , -1};
}

int main()
{
    
    return 0;
}