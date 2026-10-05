#include <bits/stdc++.h>
using namespace std;

bool canWePlaceBall(vector<int> &positions , int force , int m)
{
    int cntBall = 1 , lastBall = positions[0];
    for(int i = 0; i < positions.size(); i++)
    {
        if(positions[i] - lastBall >= force)
        {
            cntBall++; 
            lastBall = positions[i];
        }

        if(cntBall >= m) return true; 
    } 

    return false;
}

int maxDistance(vector<int> &positions , int m)
{
    sort(positions.begin() , positions.end()); 
    int low = 1 , high = positions[positions.size() - 1] - positions[0]; 

    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(canWePlaceBall(positions , mid , m) == true)
            low = mid + 1; 
        else{
            high = mid - 1;
        }
    }

    return high;
}

int main()
{
    vector<int> a = {1,2,3,4,7}; 

    // fn call 
    cout << maxDistance(a , 3) << endl; 
    return 0;
}