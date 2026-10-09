#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7; 
int findP(long long x , long long y)
{
    // base case 
    if(y == 0) return 1; 
    long long half = findP(x , y / 2); 
    long long result = (half * half) % M; 

    if(y % 2 == 1)
        result = (x * result) % M; 
    
    
    return result; 
}

long long goodNumbers(long long n)
{
    // even pos 
    long even = (n + 1) / 2; 
    // odd pos
    long prime = n / 2; 

    long long evePos = findP(5 , even);
    long long oddPos = findP(4 , prime); 

    return (evePos * oddPos) % M;
}

int main()
{
    // fnc call 
    cout << goodNumbers(50) << endl; 
    return 0;
}