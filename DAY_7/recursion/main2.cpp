#include <bits/stdc++.h>
using namespace std;

//parameterized way
void Sum(int i , int sum)
{
    if(i < 0)
    {
        cout << sum; 
        return;
    }
    Sum(i-1,sum + i);

}

// my way
int Sum2(int i, int n)
{
    if(i > n) return 0; 
    return Sum2(i+1, n) + i; 
}

int factorial(int n)
{
    //checking for -ve input
    if(n < 0) return 0;
    if(n == 1 || n == 0) return 1; 
    return factorial(n - 1) * n; 
}

//Parameterized way
void factorial2(int i , int fact)
{
    if(i == 0)
    {   
        cout << fact;
        return;
    }
    factorial2(i-1, fact * i);
}

int main()
{

    
    factorial2(5,1);

    cout << '\n';
    return 0;
}