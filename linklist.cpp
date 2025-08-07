#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) 
    {
        data = val;
        next = NULL;
    }
 
};
class list{
    Node* head;
    Node* tail;
    list() 
    {
        head = NULL;
        tail = NULL;
    }
    void push_front(int val) 
    {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
       
    }
};



int main()
{
   
    
}