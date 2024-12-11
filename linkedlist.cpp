#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
void insertAtHead(Node* &head,int val)
{
    Node* new_Node=new Node(val);
    new_Node->next=head;
    head= new_Node;
}
void insertAtTail(Node* &head,int val)
{
    Node*new_node=new Node(val);
    Node* temp=head;
    
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
        temp->next=new_node;
    }
    
void insertAtMid(Node* &head,int val,int pos)
{
    if(pos==0){
        insertAtHead(head,val);
        return;
    }
    Node*new_node= new Node(val);
    Node* temp=head;
    int current_pos=0;
     while(current_pos!=pos-1)
    {
        temp=temp->next;
        current_pos++;
    }
        new_node->next=temp->next;
        temp->next=new_node;
    }
void updateAtMid(Node* &head,int val,int pos)
{
 
    Node* temp=head;
    int current_pos=0;
     while(current_pos!=pos-1)
    {
        temp=temp->next;
        current_pos++;
    }
       temp->data=val;
    }
    void deleteAtHead(Node* &head)
    {
        Node* temp=head;
        head=head->next;
        free(temp);
    }
    void deleteAtTail(Node* &head)
    {
        Node* temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        Node* temp2=temp->next;
        temp->next=NULL;
        free(temp2);
    }
    void deleteAtMid(Node* &head,int pos)
    {
        if(pos==0){
        deleteAtHead(head);
        return;
    }
    Node* prev=head;
    int current_pos=0;
     while(current_pos!=pos-1)
    {
        prev=prev->next;
        current_pos++;
    }
        Node* temp=prev->next;
        prev->next=temp->next;
        free(temp);
    }

void display(Node* head){
    Node* temp = head;
    while(temp!= NULL)
{
    cout<<temp->data<<"->";
    temp=temp->next;
}
cout<<"NULL"<<endl;
}
int main() {
    Node* head =NULL;
    display(head);
    
    insertAtHead(head,20);
    display(head);
    
    insertAtHead(head,10);
    display(head);
    
    insertAtTail(head,30);
    display(head);
    
    insertAtMid(head,45,2);
    display(head);
    
     insertAtMid(head,2,0);
    display(head);
    
    updateAtMid(head,25,3);
    display(head);
    
    deleteAtHead(head);
    display(head);
    
    deleteAtTail(head);
    display(head);
    
    deleteAtMid(head,2);
    display(head);
    
      deleteAtMid(head,1);
    display(head);
    
    deleteAtMid(head,0);
    display(head);
    return 0;
}
