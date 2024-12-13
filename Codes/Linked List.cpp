
//Reverse Linked list in groups
#include <iostream>
using namespace std;

struct Node
{
    int data;   //Data part of the list
    Node* next;
    
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
    private:
    Node* head;
    public:
    int count=0;
    LinkedList()
    {
        head = nullptr;
    }
    
    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);
        if(head == nullptr)
        {
            cout<<"List is empty"<<endl;
            head = newNode;
            count++;
        }
        else
        {
            Node* temp = head;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            count++;
        }
    }
   
  
    
    void reverseList()
    {
        Node* current = head;
        Node* prev = nullptr;
        Node* nnext = nullptr;
        while(current != nullptr)
        {
            nnext = current->next;
            current->next = prev;
            prev = current;
            current = nnext;
        }
        head = prev;
    }
    
    void deleteNode(int value)
    {
        if(head == nullptr)
        {
            cout<<"Empty list. No elements to delete"<<endl;
            return;
        }
        //Check if node to be deleted is head node
        if(head->data == value)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout<<"Node with value "<<value<<" deleted"<<endl;
            count--;
            return;
        }
        //Traverse the list to find the node to be deleted
        Node* temp = head;
        Node* prev = nullptr;
        while(temp != nullptr && temp->data != value)
        {
            prev = temp;
            temp = temp->next;
        }
        //If value not found
        if(temp == nullptr)
        {
            cout<<"Node with value "<<value<<" not found in the list"<<endl;
            return;
        }
        
        //unlink node and delete it
        prev->next = temp->next;
        delete temp;
        cout<<"Node with value "<<value<<" deleted"<<endl;
        count--;
    }
    
    void display()const
    {
        if(head == nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp = head;
        while(temp != nullptr)
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
 

    ~LinkedList()
    {
        Node*  temp;
        while(head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
//     int countLinkedList(){
//     Node*temp=head;
//     int count=0;
//     while(temp!=nullptr){
//         count++;
//         temp=temp->next;
//     }
//     return count;
// }
void swap_nodes(int first,int second){
    Node*current=head;
    Node*prev=head;
    while(current->data!=first){
        prev=current;
        current=current->next;
    }
    Node*firstprev=prev;
    Node*firstNode=current;
    Node*firstNodeNext=current->next;
    while(current!=nullptr && current->data!=second){
        prev=current;
        current=current->next;
    }
    Node*secondprev=prev;
    Node*secondNode=current;
    Node*secondNodeNext=nullptr;
    if(current->next!=nullptr) secondNodeNext=current->next;
    firstprev->next=secondNode;
    secondprev->next=firstNode;
    secondNode->next=firstNodeNext;
    firstNode->next=secondNodeNext;
    if(head==firstNode){
        head=secondNode;
    }  
}
};

int main()
{
    
    LinkedList llist;
    for(int i = 0; i< 10; i++)
        llist.insertAtEnd((i+1)*10);
    llist.display();  
    llist.reverseList();
    llist.display();   
    llist.deleteNode(50);
    llist.deleteNode(110);
    llist.display();
    // int lcount=llist.countLinkedList();
    cout<<llist.count<<endl;
    llist.display();
    llist.deleteNode(10);
    llist.deleteNode(100);
    llist.display();
    //llist.reverseList(); 
    //  lcount=llist.countLinkedList();
    cout<<endl<<llist.count<<endl;
    
    llist.display();
    llist.insertAtEnd(100);
    llist.display();
    llist.swap_nodes(80,40);
    llist.display();
    llist.swap_nodes(90,100);
    llist.display();
    return 0;
}

