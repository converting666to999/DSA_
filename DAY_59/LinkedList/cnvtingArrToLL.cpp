#include <iostream>
#include <vector>
using namespace std;


struct Node{

public: 
    int data; 
    Node* next; 

    //constructor
    Node(int val , Node* addr)
    {
        data = val; 
        next = addr;
    }

    Node(int val)
    {
        data = val; 
        next = nullptr;
    }

};

Node* cnvrtarr2LL(vector<int> &arr)
{
    Node* head = new Node(arr[0]); 
    Node* mover = head; 
    
    for(int i = 1; i < arr.size(); ++i)
    {
        Node* temp = new Node(arr[i]);
        mover-> next = temp;
        mover = temp;
    }

    return head;
}

// search 
// O(n) avg complexity
// O(1) best case if head itself is key element
// O(n/2) if the key element is somewhere in the middle
    bool ifPresent(Node* head , int val)
    {
        Node* temp = head; 
        while(temp)
        {
            if(temp -> data == val) return true;
            temp = temp -> next;
        }    

        return false;
    }

int main()
{
    vector<int> arr = {12 , 3 , 4 , 8 , 0}; 
    Node* head = cnvrtarr2LL(arr);
    
    cout << head-> data << endl; 

    // traversal
    Node* temp = head;
    
    while(temp)
    {
        cout << temp -> data << " "; 
        temp = temp -> next;
    }

    cout << endl; 

    return 0;
}