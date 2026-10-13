#include <bits/stdc++.h>
using namespace std;

void insertAtbottom(stack<int> &st , int ele)
{
    // base case
    if(st.empty())
    {
        st.push(ele); 
        return; 
    }


    int top = st.top();
    st.pop();
    insertAtbottom(st , ele); 
    st.push(top); 

}

void reverseStack(stack<int> &st)
{
    // base case 
    if(st.empty())
        return; 

    int top = st.top(); 
    st.pop(); 

    reverseStack(st);
    insertAtbottom(st , top); 
}

int main()
{
    
    return 0;
}