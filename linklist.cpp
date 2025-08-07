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
    public:
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
    void printll() 
    {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void push_back(int val) 
    {
        Node* newNode = new Node(val);
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_front() 
    {
        if (head == NULL) return; // List is empty
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) tail = NULL; // If the list becomes empty
    }
    void pop_back() 
    {
        if (head == NULL) return; // List is empty
        if (head == tail) { // Only one element
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
    void insert_position(int val, int pos) 
    {
      if(pos==0)
        {
            push_front(val);
            return;
        }
        if(pos<0)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        Node* temp=head;
        for(int i=0;i<pos-1;i++)
        {
            temp= temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void search(int val) 
    {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Value " << val << " found in the list." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Value " << val << " not found in the list." << endl;
    }
};



int main()
{
   list ll;

   ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_back(40);
    ll.push_back(50);

    ll.printll(); // Output: 30->20->10->

    ll.pop_front();
    ll.printll();

    ll.pop_back();
    ll.printll();

    ll.insert_position(35, 2);
    ll.printll();
   return 0;
   
    
}