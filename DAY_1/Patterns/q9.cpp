#include <iostream>
using namespace std;

void pattern7(int n)
{
    for(int i = 0; i < n; i++)
    {   
        // space
        for(int j = 1; j <= n-i-1; j++)
        {
            cout << " ";
        }

        // stars
         for(int j = 1; j <= 2*i + 1; j++)
        {
            cout << "*";
        }

        // space
         for(int j = 1; j <= n-i-1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern8(int n)
{
    for(int i = 0; i < n; i++)
    {   
        // space
        for(int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // stars
         for(int j = 0; j < 2*(n-i)-1; j++)
        {
            cout << "*";
        }

        // space
         for(int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
 
int main()
{
    int n; 
    cin >> n; 

    pattern7(n); 
    pattern8(n);
    return 0;
}