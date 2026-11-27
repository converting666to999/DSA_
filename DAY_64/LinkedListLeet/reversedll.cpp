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

class DoublyListNode {
public:
    int val;
    DoublyListNode *prev;
    DoublyListNode *next;
    DoublyListNode() : val(0), prev(nullptr), next(nullptr) {}
    DoublyListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
    DoublyListNode(int x, DoublyListNode *prev, DoublyListNode *next) : val(x), prev(prev), next(next) {}
};

class Solution {
public:
        // brute
        DoublyListNode* reverse(DoublyListNode* head)
        {
            stack<int> ms; 
            DoublyListNode* temp = head; 

            while(temp)
            {
                ms.push(temp -> val);
                temp = temp -> next;
            }

            // resetting
            temp = head;

            while(temp)
            {
                temp -> val = ms.top();
                ms.pop(); 
                temp = temp -> next; 
            }

            return head;
        }

        DoublyListNode* reverseOp(DoublyListNode* head)
        {
            DoublyListNode* curr = head;
            DoublyListNode* last = nullptr; 

            while(curr != nullptr)
            {
                last = curr -> prev;
                curr -> prev = curr -> next; 
                curr -> next = last; 

                curr = curr -> prev;
            }

            head = last -> prev; 
            return head;
        }

};