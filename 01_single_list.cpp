#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
        //destructor
    ~node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtIndex(node *&head, node *&tail, int d, int index)
{
    if (index == 1)
    {
        insertAtHead(head, d);
        return;
    }
    node *temp = new node(d);
    node *ptr = head;
    int cnt = 1;
    while (cnt < index - 1)
    {
        ptr = ptr->next;
        cnt++;
    }
    if (ptr->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    temp->next = ptr->next;
    ptr->next = temp;
}
void deleteNode(int position, node* & head) { 

    //deleting first or start node
    if(position == 1) {
        node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {

        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    insertAtHead(head, 9);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    print(head);
    insertAtTail(tail, 11);
    insertAtTail(tail, 12);
    print(head);
    insertAtIndex(head, tail, 13, 3);
    print(head);
    deleteNode(1,head) ;
    print(head);

    deleteNode(3,head) ;
    print(head);



    return 0;
}