#include <iostream>
using namespace std;

void pattern19(int n)
{
    for(int i = 0; i < n;i++)
    {
        //stars
        for(int j = 0; j < n - i; j++)
        {
            cout << "*";
        }

        //space
        for(int j = 0; j < 2*i; j++)
        {
            cout << " ";
        }

        //stars
        for(int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
 
void pattern19_p2(int n)
{
    for(int i = 1; i <= n;i++)
    {
        //stars
        for(int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        //space
        for(int j = 1; j <= 2 * (n-i); j++)
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
 

int main()
{
    int n;
    cin >> n;

    pattern19(n);
    pattern19_p2(n);
    return 0;
}