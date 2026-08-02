#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if( n <= 1) return n;
    // Multiple recursive calls
    int last = fibonacci(n - 1); 
    int last_sec = fibonacci(n - 2); 

    return last + last_sec;
}

int main()
{

    int n; 
    cin >> n; 

    cout << fibonacci(n);


    cout << "\n";

    return 0;
}