#include <iostream> 
#include <vector> 

using namespace std;

class Node{

public: 
    int data; 
    Node* next; 

public:
    Node(int val , Node* addr)
    {
        data = val; 
        next = addr;
    }

    Node(int val)
    {
        data = val;
    }

};


int lenght(Node* &head)
{
    Node* temp = head; 
    int cnt = 0; 

    // traversing
    while(temp)
    {
        temp = temp -> next;
        cnt++;
    }

    return cnt;
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

int main(){

    vector<int> arr = {1 , 2 , 3 , 4 ,5, 8};
    Node* head = convertingArrToLL(arr);

    // fn call
    printf("lenght of the list is %d\n" , lenght(head));
    return 0;
}