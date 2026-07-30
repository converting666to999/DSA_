#include <bits/stdc++.h>
using namespace std;


// tc o(sqrt(n))
void isPrime(int n)
{
    int cnt = 0;
    for(int i = 1; i <= sqrt(n); i++)
    {   
        // checks the first factor
        if(n % i == 0) cnt++;
        // checks the second factor
        if(n / i != i) cnt ++;
    }
    if(cnt == 2) cout << "prime number" << '\n';
    else cout << "not a prime number" << '\n';  

}

int main()
{

    int n; 
    cin >> n; 

    isPrime(n); 
    return 0;
}