#include <iostream>
using namespace std;

void pattern11(int n)
{
    int print = 1;
    for(int i = 0; i <= n; i++)
    {   
        if (i % 2 == 0) print = 1;
        else print = 0;
        for(int j = 0; j < i; j++)
        {
            cout << print << " ";
            //flip
            print = 1 - print;
        }
        cout << endl;
    }
}
 
int main()
{
    int n; 
    cin >> n; 
    
    pattern11(n);
    return 0;
}