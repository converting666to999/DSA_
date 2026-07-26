#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    //basically array but with dynamic size 

    vector<int> v; 

    v.emplace_back(1);
    v.emplace_back(2);

    //vector of pairs 
    vector<pair<int,int>> nums; 

    // nums.push_back({2,3});
    // nums.emplace_back(4,5);

    // cout << v[0] << '\n';
    // cout << nums[1].second; 

    vector<int> a(5,100);
    vector<int> b(a);
    vector<int> c;

    b.emplace_back(200);

    c.push_back(10 );
    c.emplace_back(30);
    c.emplace_back(40);
    c.emplace_back(50);
    c.emplace_back(60);

    //iterator
    vector<int>::iterator it = a.begin();
    vector<int>::iterator it_end = a.end();

    // cout << *(it) << '\n';

    // while(it != it_end)
    // {
    //     cout << *(it) << " "; 
    //     it++;
    // }
    
    // for(int i = 0; i < 6; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // return 0;

    // cout << a.back();

    for(auto it = c.begin(); it != c.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;

    // for each loop
    for(auto it : c)
    {
        cout << it << " ";
    }
}