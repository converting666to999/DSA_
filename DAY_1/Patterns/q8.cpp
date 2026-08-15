#include <iostream>
using namespace std;

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

    pattern8(n);
    return 0;
}