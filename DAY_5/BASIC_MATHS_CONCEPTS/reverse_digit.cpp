#include <iostream> 
using namespace std;

// similar to extraction of digit
int reverse_digit(int n)
{   
    int r_digit = 0;
    while(n > 0)
    {
        // last digit extract krne ke liye
        int ls_digit = n % 10;
        // reverse number form krne ke liye
        r_digit = (r_digit * 10) + ls_digit;
        n = n / 10;
    }
    return r_digit;
}

int main()
{
    int n; 
    cin >> n;

    cout << reverse_digit(n);
    
    cout << '\n';
    return 0;
}