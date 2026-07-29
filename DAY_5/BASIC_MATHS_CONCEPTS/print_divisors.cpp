#include <bits/stdc++.h>
using namespace std;

// tc is O(n)
// void Divisors(int n)
// {
//     for(int i = 1; i <= n; i++)
//     {
//         if(n % i == 0)
//         {
//             cout << i << " ";
//         }
//     }
// }

// better way to do that
// tc will be O(sqrt(N))
vector<int> Divisors(int n)
{   
    vector<int> divisor; 
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            // 1st factor
            divisor.push_back(i);
            // 2nd factor
            if(n / i != i) divisor.push_back(n / i);
        }
        
    }

    sort(divisor.begin(), divisor.end());
    return divisor; 
}

int main()
{
    int n; 
    cin >> n;

    // Divisors(n);

    // vector<int> ans = Divisors(n);

    for(auto it : Divisors(n))
    {
        cout << it << " "; 
    }
    
    cout << '\n';
    return 0;
}