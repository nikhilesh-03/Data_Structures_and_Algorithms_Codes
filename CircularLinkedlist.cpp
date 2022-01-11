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

class circular_linked_list{
    public:
    node *head;
    node *tail;
    int size=0;
    circular_linked_list(){
        head=NULL;
        tail=NULL;
    }
    void insert_front(node*curr, int x){
        size++;
        node *temp=new node(x);
        cout<<"Element inserted into the front of the linked list :"<<x<<endl;
        if(head==NULL){
            temp->next=temp;
            temp->prev=temp;
            head=tail=temp;
        }
        else{
            temp->next=curr;
            curr->prev=temp;
            temp->prev=tail;
            tail->next=temp;
            head=temp;
        }
    }
    void insert_back(node*curr_tail, int x){
        size++;
        node *temp=new node(x);
         cout<<"Element inserted into the back of the linked list :"<<x<<endl;
        if(curr_tail==NULL){
            temp->next=temp;
            temp->prev=temp;
            head=tail=temp;
        }
        else{
            curr_tail->next=temp;
            temp->prev=curr_tail;
            temp->next=head;
            head->prev=temp;
            tail=temp;
        }
    }
    void delete_front(node*curr_head){
        size--;
        if(curr_head==NULL){
            head=tail=curr_head;
        }
        else if(curr_head->next==curr_head){
            cout<<"Element deleted from the front of the linked list :"<<curr_head->data<<endl;
            head=tail=NULL;
        }
        else{
            cout<<"Element deleted from the front of the linked list :"<<curr_head->data<<endl;
            curr_head=curr_head->next;
            curr_head->prev=tail;
            tail->next=curr_head;
            head=curr_head;
        }
    }
    void delete_back(node *curr_tail){
        size--;
        if(curr_tail==NULL){
            head=tail=NULL;
        }
        else if(head==curr_tail){
            cout<<"Element deleted from the end of the linked list :"<<curr_tail->data<<endl;
            head=tail=NULL;
        }
        else{
            cout<<"Element deleted from the end of the linked list :"<<curr_tail->data<<endl;
            node *temp;
            temp=curr_tail->prev;
            temp->next=head;
            head->prev=temp;
            tail=temp;
        }
    }
    void delete_from_kth_node(node *curr_head ,node *curr_tail, int k){
        k=k%(size+1);
        cout<<"Element deleted at "<<k<<"th node :";
        if(head==NULL){
            head=tail=NULL;
        }
        else if(curr_head->next==head){
            size--;
            cout<<curr_head->data<<endl;
            head=tail=NULL;
        }
        else if(k==1){
            size--;
            node *temp=curr_head;
            cout<<temp->data<<endl;
            curr_head=curr_head->next;
            curr_head->prev=tail;
            tail->next=curr_head;
            delete (temp);
            head=curr_head;
        }
        else if (k==size){
            cout<<curr_tail->data<<endl;
            node*temp=curr_tail;
            curr_tail=curr_tail->prev;
            curr_tail->next=head;
            head->prev=curr_tail;
            tail=curr_tail;
            size--;
            delete (temp);
        }
        else{
            size--;
            int pos=k-2;
            while(pos>0){
                curr_head=curr_head->next;
                --pos;
            }
            cout<<curr_head->next->data<<endl;                 
            curr_head->next=curr_head->next->next;
            curr_head->next->next->prev=curr_head;
        }
    }
    void transverse(node *curr_head, node*curr_tail){
        cout<<"Circular linked list :";
        while(curr_head!=curr_tail){
            cout<<curr_head->data<<" ";
            curr_head=curr_head->next;
        }
        cout<<tail->data<<endl;
    }

};

int main(){
    int n,a;
    cin>>n;
    circular_linked_list nvg;
    for(int i=0;i<n;i++){
        cin>>a;
        nvg.insert_front(nvg.head,a);
        nvg.transverse(nvg.head, nvg.tail);
    }
    nvg.insert_back(nvg.tail,21);
    nvg.transverse(nvg.head,nvg.tail);
    nvg.insert_back(nvg.tail,17);
    nvg.transverse(nvg.head,nvg.tail);
    nvg.insert_front(nvg.head,7);
    nvg.transverse(nvg.head,nvg.tail);
    nvg.insert_back(nvg.tail,2);
    nvg.transverse(nvg.head,nvg.tail);
    nvg.insert_back(nvg.tail,5);
    nvg.transverse(nvg.head,nvg.tail);
    nvg.delete_front(nvg.head);
    nvg.transverse(nvg.head,nvg.tail);
    nvg.delete_front(nvg.head);
    nvg.transverse(nvg.head,nvg.tail);
    nvg.delete_back(nvg.tail);
    nvg.transverse(nvg.head,nvg.tail);
    nvg.delete_back(nvg.tail);
    nvg.transverse(nvg.head,nvg.tail);
    nvg.delete_from_kth_node(nvg.head,nvg.tail,4);
    nvg.transverse(nvg.head, nvg.tail);
    nvg.delete_from_kth_node(nvg.head,nvg.tail,3);
    nvg.transverse(nvg.head, nvg.tail);
    return 0;
}