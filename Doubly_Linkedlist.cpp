#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *prev;
    node *next;
    node(int x){
        data=x;
        prev=NULL;
        next=NULL;
    }
};
class doubly_linked_list{
    public:
    node *head;
    node *tail;
    doubly_linked_list(){
        head=NULL;
        tail=NULL;
    }
    void insert_front(int x){
        node *temp=new node(x);
        cout<<"Element pushed front into the linked list :"<<x<<endl;
        if(head==NULL){
            temp->next=NULL;
            head=temp;
            tail=temp;
        }
        else{
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
    }
    void insert_back(node*old_tail,int x){
        node*temp=new node(x);
        cout<<"Element pushed back into the linked list :"<<x<<endl;
        if(head==NULL){
            temp->next=NULL;
            head=temp;
            tail=temp;
        }
        else{
            old_tail->next=temp;
            temp->prev=old_tail;
            tail=temp;
        }
    }
    void delete_front(node *curr){
        if(curr==NULL){
            head=curr;
        }        
        else if(curr->next==NULL){
            cout<<"Element deleted from the front of linked list :"<<curr->data<<endl;
            curr->prev=NULL;
            curr->prev=NULL;
            head=curr;
        }
        else{
            cout<<"Element deleted from the front of linked list :"<<curr->data<<endl;
            curr->next->prev=NULL;
            curr=curr->next;
            head=curr;
        }
    }
    void delete_back(node *old_tail){
        if(old_tail==NULL){
            tail=old_tail;
        }
        else if(old_tail==head){
            cout<<"Element deleted from the back of linked list :"<<old_tail->data<<endl;
            tail=head=NULL;
        }
        else{
            cout<<"Element deleted from the back of linked list :"<<old_tail->data<<endl;
            node *temp=old_tail->prev;
            temp->next=NULL;
            tail=temp; 
        }
    }

    void remove(int y){
        node *curr_head=head;
        while(curr_head!= NULL && curr_head->data!=y){
            curr_head=curr_head->next;
        }
        if(curr_head==NULL){
            head=head;
        }
        else if(curr_head==head){
            cout<<"Element removed from linked list :"<<y<<endl;
            curr_head=curr_head->next;
            curr_head->prev=NULL;
            head=curr_head;
        }
        else{
            cout<<"Element removed from linked list :"<<y<<endl;
            node *temp;
            temp=curr_head->prev;
            temp->next=curr_head->next;
            curr_head->next->prev=temp;
        }
    }

    void transverse(node *curr){
        cout<<"linked list :";
        while(curr!=NULL){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }

    void reverse(node*curr_head){
        cout<<"Reverse ";
        node *temp=NULL;
        while(curr_head!=NULL){
            temp=curr_head->next;
            curr_head->next=curr_head->prev;
            curr_head->prev=temp;
            curr_head=curr_head->prev;
        }
        swap(head,tail);
    }
};

int main(){
    int n,a;
    cin>>n;
    doubly_linked_list nvg;
    for(int i=0;i<n;i++){
        cin>>a;
        nvg.insert_front(a);
        nvg.transverse(nvg.head);
    }
    nvg.insert_back(nvg.tail,21);
    nvg.transverse(nvg.head);
    nvg.insert_back(nvg.tail,17);
    nvg.transverse(nvg.head);
    nvg.insert_front(7);
    nvg.transverse(nvg.head);
    nvg.insert_back(nvg.tail,2);
    nvg.transverse(nvg.head);
    nvg.insert_back(nvg.tail,5);
    nvg.transverse(nvg.head);
    nvg.reverse(nvg.head);
    nvg.transverse(nvg.head);
    nvg.delete_front(nvg.head);
    nvg.transverse(nvg.head);
    nvg.delete_front(nvg.head);
    nvg.transverse(nvg.head);
    nvg.delete_back(nvg.tail);
    nvg.transverse(nvg.head);
    nvg.delete_back(nvg.tail);
    nvg.transverse(nvg.head);
    nvg.remove(21);
    nvg.transverse(nvg.head);
    nvg.remove(6);
    nvg.transverse(nvg.head);
    nvg.remove(17);
    nvg.transverse(nvg.head);
    //nvg.delete_back(nvg.tail);
    //nvg.transverse(nvg.head);
    //nvg.delete_back(nvg.tail);
    //nvg.transverse(nvg.head);
    //nvg.delete_back(nvg.tail);
    //nvg.transverse(nvg.head);
    return 0;
}