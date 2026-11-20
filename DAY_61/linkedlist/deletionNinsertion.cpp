#include <iostream>
#include <vector> 
using namespace std;

class Node
{
public: 
    int data; 
    Node* next; 

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

// *****************************Deletion*****************************

// deletes head
Node* dltHead(Node* &head)
{
    Node* temp = head; 
    head = head -> next; 
    free(temp); 

    return head;
}

// deletes tail
Node* dltTail(Node* &head)
{
    Node* temp = head; 

    while(temp -> next -> next != nullptr)
    {
        temp = temp -> next;
    }

    free(temp -> next);
    temp -> next = nullptr; 

    return head;
}

Node* dltKelement(Node* &head , int k)
{
     if(head == nullptr)
        return nullptr; 

    if(k == 1)
       return dltHead(head);

    int cnt = 0; 
    Node* temp = head; 
    Node* prev = nullptr;

    while(temp)
    {
        cnt++; 

        if(cnt == k)
        {   
            prev -> next = prev -> next -> next;
            free(temp); 
            break;
        }
        prev = temp; 
        temp = temp -> next;
    }

    return head;

}

Node* dltElement(Node* &head , int el)
{
     if(head == nullptr)
        return nullptr; 

    if(head -> data == el)
       return dltHead(head);

    Node* temp = head; 
    Node* prev = nullptr;

    while(temp)
    {

        if(temp -> data == el)
        {   
            prev -> next = prev -> next -> next;
            free(temp); 
            break;
        }
        prev = temp; 
        temp = temp -> next;
    }

    return head;

}

Node* convertingArrToLL(vector<int> &arr)
{
    Node* head = new Node(arr[0]); 
    Node* mover = head; 

    for(int i = 1; i < arr.size(); i++)
    {   
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }

    return head; 
}

// print all LL nodes
void print(Node* &head)
{
    Node* temp = head;

    while(temp)
    {
        cout << temp -> data << " "; 
        temp = temp -> next;
    }
}

// *****************************Insertion*****************************

Node* InsertAtHead(Node* &head , int val)
{
    Node* temp = head;

    head = new Node(val);
    head -> next = temp;
    return head;
}

Node* InsertAtlast(Node* &head , int val)
{

    // edge case
    if(head == nullptr)
        return head = new Node(val);

    Node* temp = head;
    
    while(temp -> next != nullptr)
    {
        temp = temp -> next;
    }

    temp -> next = new Node(val);
    return head;
}

// with prev pointer
Node* InsertAtK(Node* &head , int k , int val)
{
    if(head == nullptr)
        return head = new Node(val); 

    if(k == 1)
        return InsertAtHead(head, val);

    int cnt = 0;
    Node* temp = head; 
    Node* prev = nullptr; 

    while(temp)
    {
        cnt++; 

        if(cnt == k)
        {
            prev -> next = new Node(val , temp);
            break;
        }

        prev = temp;
        temp = temp -> next;
    }

    if(prev -> next == nullptr)
    {
       prev -> next = new Node(val); 
    }

    return head;

}

// without prev pointer
Node* InsertAtK_(Node* &head , int k , int val)
{
    if(head == nullptr)
        return head = new Node(val); 

    if(k == 1)
        return InsertAtHead(head, val);

    int cnt = 0;
    Node* temp = head;

    while(temp)
    {
        cnt++; 

        if(cnt == k - 1)
        {
            Node* x = new Node(val , temp -> next); 
            temp -> next = x; 
            break;
        }

        temp = temp -> next;
    }


    return head;
}

// did with previous pointer
Node* InsertB4xEl(Node* &head , int x , int val)
{
    if(head == nullptr)
        return head = new Node(val); 

    if(head -> data == x)
        return InsertAtHead(head, val);

    // int cnt = 0;
    Node* temp = head;
    bool fnd = false;

    while(temp -> next != nullptr)
    {
        // cnt++; 

        if(temp -> next -> data == x)
        {
            Node* x = new Node(val , temp -> next);
            temp -> next = x;
            fnd = true;
            break;
        }

        temp = temp -> next;
    }

    if(fnd == false)
        printf("enter the value thats in the linked list nigger \n");

    return head;

}

int main()
{
    vector<int> arr = {1 , 2 , 4, 6, 9};

    Node* head = convertingArrToLL(arr); 
    
    head = InsertB4xEl(head, 12, 100);
    print(head);

    cout << endl;
    return 0;
}