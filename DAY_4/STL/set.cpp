#include <bits/stdc++.h>
using namespace std;

int main()
{

    set<int> st; 

    st.insert(1); 
    st.insert(2); 
    st.insert(2); 
    st.insert(3); 
    st.insert(3); 
    st.insert(4); 

    // auto it = st.find(3);

    // auto it = st.count(8);

    auto it1 = st.find(2); 
    auto it2  = st.find(4); // we give next element of the element we want to erase

    st.erase(it1, it2);

    for(auto it : st)
    {
        cout << it << " ";
    }

 

    cout << '\n';
    return 0;
}