#include <iostream>
#include <vector> 

using namespace std;

class Node{

public: 

    int data; 
    Node* prev; 
    Node* next; 

    // constructor

    Node(int val , Node* frwd , Node* bkcwrd)
    {
        data = val; 
        prev = bkcwrd; 
        next = frwd; 
    }

    Node(int val)
    {
        data = val; 
        prev = nullptr;
        next = nullptr;
    }
}; 

// converting arr to DLL

Node* cnvrtArrToDll(vector<int> &arr)
{
    Node* head = new Node(arr[0]); 
    Node* prev = head; 

    for(int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i] , nullptr , prev);
        prev -> next = temp; 
        prev = temp; 
    }

    return head;
}

Node* Insertb4Head(Node* &head , int val)
{
    Node* newHead = new Node(val); 
    newHead -> next = head; 
    head -> prev = newHead;

    return newHead;
}

Node* InsertAtEnd(Node* &head , int val)
{
    // edge case if there's only one element in the DLL
    if(head -> next == nullptr)
        return Insertb4Head(head , val);

    Node* tail = head; 

    while(tail -> next != nullptr)
        tail = tail -> next; 

    Node* back = tail -> prev; 

    Node* newNode = new Node(val , tail , back); 
    back -> next = newNode; 
    tail -> prev = newNode;

    return head; 

}

// inserting before the k Element
Node* Insertb4Kele(Node* &head , int k , int val)
{
    Node* kNode = head; 
    int cnt = 0;

    if(k == 1)
        return head = Insertb4Head(head , val);

    while(kNode -> next != nullptr)
    {
        cnt++; 
        if(cnt == k) break;
        kNode = kNode -> next; 
    }

    Node* back = kNode -> prev; 

    Node* newNode = new Node(val , kNode , back); 
    back -> next = newNode; 
    kNode -> prev = newNode;

    return head;

}

void Insertb4Node(Node* temp , int val)
{
    Node* back = temp -> prev; 


    Node* newNode = new Node(val , temp , back);
    back -> next = newNode; 
    temp -> prev = newNode;
}

void print(Node* head)
{
    Node* temp = head; 

    while(temp)
    {
        printf("%d " , temp -> data);
        temp = temp -> next; 
    }

    cout << endl; 
}

int main(){

    vector<int> arr = {1 , 2 , 3 , 4 , 6}; 

    Node* head = cnvrtArrToDll(arr);
    
    // fn call
    // head = Insertb4Head(head, 8);
    // head = Insertb4Kele(head , 8, 8);
    Insertb4Node(head -> next -> next -> next , 5); 
    

    // print
    print(head);
    return 0;
}