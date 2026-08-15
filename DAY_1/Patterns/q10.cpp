#include <iostream>
using namespace std;

void pattern10(int n)
{   
    for(int i = 0; i < 2*n; i++)
    {   
        int start = i;
        for(int j = 0; j < start; j++)
        {
            cout << "*";
            if(start > n)
            {
                start = 2*n - i;
            }
        }
        cout << endl;
    }

}
 
int main()
{
    int n; 
    cin >> n;

    pattern10(n);
    return 0;
}