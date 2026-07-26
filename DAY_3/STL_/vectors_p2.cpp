#include <bits/stdc++.h>
using namespace std;
 
int main()
{   
    // deletion in vector
    vector<int> v1; 
    vector<int> v2;

    v1.push_back(10); 
    v1.emplace_back(20); 
    v1.emplace_back(30); 
    v1.emplace_back(40); 

    v2.push_back(50); 
    v2.emplace_back(60); 
    v2.emplace_back(70); 
    v2.emplace_back(80); 

    // v1.erase(v1.begin()+1,v1.begin()+3);
    // v1.insert(v1.begin()+1,300);
    // v1.insert(v1.begin()+1,5,5);
    // v1.pop_back();
    // v1.size();
    // v1.clear();
    v1.swap(v2);

    for(auto it : v1)
    {
        cout << it << " ";
    }
 
    return 0;
}