#include <bits/stdc++.h>
using namespace std;

int findKthElement(vector<int> &a , vector<int> &b , int k)
{
    if(b.size() < a.size()) return findKthElement(b , a , k); 
    int n1 = a.size() , n2 = b.size();

    int low = min(0 ,k-n2) , high = max(k,n1); 
    
    while(low <= high){
        int cut1 = low + (high - low) / 2; 
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : a[cut1 - 1]; 
        int left2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];

        int right1= cut1 == n1 ? INT_MAX : a[cut1];
        int right2 = cut2 == n2 ? INT_MAX : b[cut2]; 

        if(left1 <= right2 && left2 <= right1)
        {
            return max(left1 , left2); 
        }

        if(left1 > right2)
            high = cut1 - 1; 
        else{
            low = cut1 + 1;
        }
    }

    return -1; 
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9}; 
    vector<int> b = {1, 4, 8, 10}; 
    
    // fn call
    cout << findKthElement(a , b , 5) << endl; 
    return 0;
}