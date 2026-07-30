#include <bits/stdc++.h>
using namespace std;

int Gcd(int n1,int n2)
{
    while(n1 > 0 && n2 > 0)
    {
        if( n1 > n2) n1 = n1 % n2;
        else n2 = n2 % n1;
    }

    if(n1 == 0) return n2; 
    return n1;

}


int main()
{

    int n,m; 
    cin >> n,m; 

    cout << Gcd(n,m);

    cout << '\n';
    return 0;
}