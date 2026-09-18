#include <bits/stdc++.h>
using namespace std;

void MergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<vector<int>> ans; 
    sort(intervals.begin() , intervals.end());

    for(int i = 0; i < n; i++)
    {
        if(ans.empty() || intervals[i][0] > ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
        }
    }

    // return ans; 

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << ' '; 
        }
        cout << endl;
    }
}

int main()
{   

    vector<vector<int>> a = {

        {1,3},
        {2,6},
        {8,10},
        {15,18}


    };

    // fn call
    MergeIntervals(a);
    
    return 0;
}