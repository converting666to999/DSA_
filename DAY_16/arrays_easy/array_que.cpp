#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int isMissing(vector<int> &arr)
{
    int n = arr.size() + 1;
    

    for(int i = 0; i <= n; i++)
    {   
        bool found = false;
        for(int j = 0; j < n - 1; j++)
        {
            if(arr[j] == i)
            {
                found = true; 
                break;
            }
        }
        if(!found) return i;

    }

    return -1;

}

// better approach using hash array
int isMissing_Better(vector<int> &arr)
{
    int n = arr.size();
    vector<int> hash(n+1,0); 

    for(int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    for(int i = 0; i < n + 1; i++)
    {
        if(hash[i] == 0)
        return i;
    }
    return -1;
}

//Optimal approach
int isMissing_Optimal(vector<int> &arr)
{
    int n = arr.size();

    int s1 = n * (n + 1) / 2; 
    int s2 = 0;

    for(int i = 0; i < n; i++)
    {
        s2 += arr[i]; 
    }

    //missing number
    return s1 - s2;

}

int isMissing_Optimal2(vector<int> &arr)
{
    int n = arr.size(); 
    int xor1 = 0; 
    int xor2 = 0; 

    for(int i = 0; i < n; i++)
    {
        xor2 = xor2 ^ arr[i]; 
        xor1 = xor1 ^ arr[i + 1];
    }

    xor1 = xor1 ^ n; 
    return xor1 ^ xor2;


}

int main()
{

	vector<int> a = {0, 2, 3, 1, 4}; 
    vector<int> b = {1, 2, 3, 6, 7}; 

    cout << isMissing_Optimal2(a);

    // for(auto it : removeDupe(a))
    // {
    //     cout << it << " ";
    // }




    

    return 0;
}