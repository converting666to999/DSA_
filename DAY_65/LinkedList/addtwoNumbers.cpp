#include <bits/stdc++.h>
using namespace std;


class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class DListNode {
public:
    int val;
    DListNode *prev;
    DListNode *next;
    DListNode() : val(0), prev(nullptr), next(nullptr) {}
    DListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
    DListNode(int x, DListNode *prev, DListNode *next) : val(x), prev(prev), next(next) {}
};

class Solution {
public:

    // broken sol^n
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    // {
    //     if(l1 == nullptr || l2 == nullptr)
    //         return new ListNode(); 

    //     stack<int> st1; 
    //     stack<int> st2; 
        
    //     while(l1){

    //         st1.push(l1 -> val);
    //         l1 = l1 -> next;
    //     }

    //     while(l2){
    //         st2.push(l2 -> val); 
    //         l2 = l2 -> next;
    //     }

    //     if(st1.empty() && st2.empty())
    //         return new ListNode(); 

    //     int n = st1.size(); 

    //     ListNode* head = new ListNode(st1.top() + st2.top());
    //     st1.pop() , st2.pop(); 

    //     ListNode* temp = head; 
        
    //     for(int i = 1; i < n; i++)
    //     {
    //         ListNode* newNode = new ListNode(); 
    //         if(st1.top() + st2.top() >= 10){
    //             st1.pop() , st2.pop();
    //             newNode -> val = 0;
    //         }
    //         else {
    //             newNode -> val = st1.top() + st2.top();
    //             st1.pop() , st2.pop(); 
    //         } 
    //         temp -> next = newNode; 
    //         temp = newNode;
    //     }
        
    //     return head;
    // }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dum = new ListNode(); 
        ListNode* temp = dum; 
        int crr = 0; 

        while(l1 != nullptr || l2 != nullptr || crr)
        {
            int sum = 0;
            if(l1 != nullptr)
            {
                sum += l1 -> val; 
                l1 = l1 -> next;
            }

            if(l2 != nullptr)
            {
                sum += l2 -> val; 
                l2 = l2 -> next;
            }

            sum += crr; 
            crr = sum / 10; 
            ListNode* newNode = new ListNode(sum % 10); 
            temp -> next = newNode; 
            temp = newNode; 
        }

        return dum -> next;
    }

};