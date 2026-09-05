#include <bits/stdc++.h>
using namespace std;


void Threesum_better(vector<int>& nums )
{   

   
    set<vector<int>> st; 

    for(int i = 0; i < nums.size(); i++)
    {   
        // declaring it under outer loop 
        // because we want set empty after each 
        // i iteration so that we can avoid 
        // duplicates
        set<int> hashSet;
        for(int j = i+1; j < nums.size(); j++)
        {   
            int k = -(nums[i] + nums[j]); 
            if(hashSet.find(k) != hashSet.end())
            {
                vector<int> temp = {nums[i],nums[j],k}; 
                sort(temp.begin(),temp.end()); 
                st.insert(temp);
            }
            // O(n);
            hashSet.insert(nums[j]); 
        }
    }

    // copied for set to 2d vector
    vector<vector<int>> ans(st.begin(),st.end());

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j  < ans[0].size(); j++)
        {
            cout << ans[i][j] << " "; 
        }
        cout << endl;
    }

    
}

void ThreeSum_Optimal(vector<int>& nums )
{
    vector<vector<int>> ans; 
    sort(nums.begin(),nums.end()); 

    for(int i = 0; i < nums.size(); i++)
    {   
        // skiping for the current iteration 
        // if previous and current value is same
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1; 
        int k = nums.size() - 1; 

        while( j < k )
        {
            int sum = nums[i] + nums[j] + nums[k];

            if(sum < 0) j++; 
            else if(sum > 0) k--; 
            else{

                vector<int> temp = {nums[i], nums[j], nums[k]}; 
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && nums[j] == nums[j - 1]) j++;
                while(j < k && nums[k] == nums[k + 1]) k--;

            }
        }
    }


    // printing output
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j  < ans[0].size(); j++)
        {
            cout << ans[i][j] << " "; 
        }
        cout << endl;
    }


}


int main()
{
    vector<int> a = {-1,0,1,2,-1,-4};

    ThreeSum_Optimal(a);
    
    return 0;
}