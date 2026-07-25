#include <iostream>
using namespace std;

void pattern20(int n)
{
    for(int i = 1; i <= n; i++)
    {
       // stars 
       for(int j = 1; j <= i; j++)
       {
        cout << "*";
       }
       //space
        for(int j = 1; j <= 2*(n-i); j++)
       {
        cout << " ";
       }
       //stars
        for(int j = 1; j <= i; j++)
       {
        cout << "*";
       }
       cout << endl; 

    }
}

void pattern20_p2(int n)
{   
    int iniS = 2;
    for(int i = 1; i <= n-1; i++)
    {
        // stars 
       for(int j = 1; j <= (n-1-i) + 1; j++)
       {
        cout << "*";
       }
       //space
        for(int j = 1; j <= iniS; j++)
       {
        cout << " ";
       }
       //stars
        for(int j = 1; j <= (n-1-i) + 1; j++)
       {
        cout << "*";
       }
       cout << endl; 
       iniS += 2;
    }

}
 
int main()
{
    int n; 
    cin >> n; 

    pattern20(n);
    pattern20_p2(n);
    return 0;
}