#include <bits/stdc++.h>
using namespace std;

double findPow(double  x , int n)
{
    double ans = 1.0; 
    long long nn = n; 

    // converting it to +ve
    if(nn < 0) -1 * nn; 
    while(nn > 0)
    {
        if(nn % 2 == 0)
        {
            x = x * x; 
            nn = nn / 2;
        }
        else{
            ans = ans * x; 
            nn--;
        }
    }
    if(nn < 0) ans = (double)(1.0) / (double)(ans); 
    return ans; 
}

int main()
{
    cout << findPow(2.00000 , 10) << endl;  
    return 0;
}