#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s; 
    cin >> s;
    
    // precompute hash array
    int hash[26] = {0};
    for(int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a'] += 1;
    }

    int q; 
    cin >> q; 
    while(q--)
    {
        char c; 
        cin >> c;
        //fetch
        cout << c << " = " << hash[c - 'a'] << " times" << endl;
    }

    return 0;
}