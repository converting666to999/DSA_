#include <bits/stdc++.h>
using namespace std;

long long ncr(int n , int r)
{   
    n = n - 1; 
    r = r - 1;
    long long  result = 1; 

    for(int i = 0; i < r; i++)
    {
        result = result * (n - i); 
        result = result / (i+1);
    }

    return result;
}

vector<int> ncr_Ithrow(int n){

    vector<int> res;

    long long ans = 1; 

    res.push_back(ans);
    for(int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        res.push_back(ans);
    }

    return res;

}

int pascalTriangle(int r , int c)
{
    return ncr(r, c);
}

int main()
{
    int row = 4;
    int col = 2;

    for(auto it : ncr_Ithrow(6))
        cout << it << " "; 

    return 0;
}