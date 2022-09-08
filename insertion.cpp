#include <iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    //making constructor...
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node* insertion_front(node* head,int data){
    node* new_node=new node(data);
    if(head==NULL){
        head=new_node;
        new_node->next=head;
    }
    else{
        new_node->next=head->next;
        head->next=new_node;
    }
    return head;
}
node* insertion_back(node* head,int data){
    node* new_node=new node(data);
    if(head==NULL){
        head=new_node;
        new_node->next=head;
    }
    else{
        new_node->next=head->next;
        head->next=new_node;
        head=new_node;
    }
    return head;
}
node* insertion_bw(node* head,int data,int k){
    node* temp=head;
    node* new_node=new node(data);
    if(head==NULL){
        head=new_node;
        new_node->next=head;
    }
    if(k==0){
        head = insertion_front(head,data);
    }
    else{
        for(int i=0;i<k;i++){
            temp=temp->next;
            if(temp==head){
                head = insertion_back(head,data);
                return head;
            }
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
    return head;
}
void traversal(node* head){
    node* temp=head->next;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
}
int main(){
    node* head=NULL;
    head = insertion_front(head,2);
    traversal(head);
    cout<<endl;
    head = insertion_front(head,90);
    traversal(head);
    cout<<endl;
    head = insertion_front(head,99);
    traversal(head);
    cout<<endl;
    head = insertion_front(head,12);
    traversal(head);
    cout<<endl;
    head = insertion_front(head,25);
    traversal(head);
    cout<<endl;
    head = insertion_front(head,23);
    traversal(head);
    cout<<endl;
    head = insertion_back(head,43);
    traversal(head);
    cout<<endl;
    head = insertion_bw(head,79,5);
    traversal(head);
    cout<<endl;
    head = insertion_bw(head,97,10);
    traversal(head);
    cout<<endl;

    return 0;
}