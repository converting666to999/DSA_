#include <bits/stdc++.h>
using namespace std;

int main()
{

    map<int , int> m1; 
    map<pair<int,int> , int> m2; 
    map<int , pair<int,int>> m3;

    

    m1.emplace(1,2);
    m1.emplace(2,4); 
    m1.emplace(3,7);

    m2[{2,3}] = 10;
    

    for(auto it : m1)
    {
        cout << it.first << " " << it.second << "\n";
    }

    // cout << m1[1]; 

    auto it = m1.find(1); 
    cout << (*it).first << '\n';


    cout << '\n';
    return 0;
}