#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    bool vis;
    node(int x){
        data=x;
        next=NULL;
        vis=false;
    }
};
bool empty(node *head){
    if(head==NULL){
        return true;
    }
    else{
        return false;
    }
}
int size(node *head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}
node *insert_front(node *curr, int x){
    cout<<"The element inserted at beginning :" << x<<endl;
    node *temp=new node (x);
    temp->next=curr;
    return temp;
}
node *insert_back(node *head, int x){
    cout<<"The element inserted at end :" << x<<endl;
    if(head==NULL){
        head=new node(x);
        return head;
    }
    else{
        node *curr=head;
        while(head->next!=NULL){
            head=head->next;
        }
        head->next=new node(x);
        return curr;
    }
}
node *delete_front(node *head){
    if(head==NULL){
        cout<<"Segmenation fault"<<endl;
        return NULL;
    }
    else{
        cout<<"The element deleted from beginning :"<<head->data<<endl;
        head=head->next;
        return head;
    }
}
node *delete_end(node *head){
    if(head==NULL){
        cout<<"Segmentation fault"<<endl;
        return NULL;
    }
    else{
        node*curr=head;
        if((size(head))==1){
            cout<<"The element deleted from end :"<<head->data<<endl;
            head=NULL;
            return head;
        }
        else{
            /*while(head->next->next!=NULL){
                head=head->next;
            }
            delete (head->next);
            head->next=NULL;
            return curr;*/
            int p=size(head)-2;
            while(p>0){
                head=head->next;
                --p;
            } 
            cout<<"The element deleted from end :"<<head->next->data<<endl;
            delete (head->next);
            head->next=NULL;
            return  curr;
        }
    }
}
node *insert(node*head,int pos,int y){
    node *temp= new node(y);
    if(pos>size(head)+1){
        return head;
    }
    else if(pos==1){
        cout<<"Element inserted at position "<<pos<<" :"<<y<<endl;
        temp->next=head;
        return temp;
    }
    else{
        cout<<"Element inserted at position "<<pos<<" :"<<y<<endl;
        node *curr=head;
        pos=pos-2;
        while(pos>0){
            head=head->next;
            --pos;
        }
        temp->next=head->next;
        head->next=temp;
        return curr;
    }
}
node *sorted_insert(node *curr_head, int x){
    node *temp= new node (x);

    if(curr_head==NULL){
        return temp;
    }
    else{
        if(x<curr_head->data){
            temp->next=curr_head;
            return temp;
        }
        else{
            node*old_head=curr_head;
            while(curr_head->next!=NULL && x>curr_head->next->data){
                curr_head=curr_head->next;
            }
            temp->next=curr_head->next;
            curr_head->next=temp;
            return old_head;
        }
    }
}
void remove_duplicate(node *curr_head){
    node *temp = curr_head;
    if(curr_head==NULL){
        return ;
    }
    else{
        while(curr_head->next!=NULL){
            if(curr_head->next->data!=curr_head->data){
                curr_head=curr_head->next;
            }
            else{
                curr_head->next=curr_head->next->next;
                curr_head=curr_head;
            }
        }
    }  
}
node *reverse_iterative(node*old_head){
    if(old_head==NULL || old_head->next==NULL){
        return old_head;
    }
    else{
        // ITERATIVE APPROACH  // Time Complexity : O(n)
        node *prev=NULL;
        node *temp=NULL;
        while(old_head!=NULL){
            temp=old_head->next;
            old_head->next=prev;
            prev=old_head;
            old_head=temp;
        }
        return prev;
    }
}
node *reverse_recursive(node *curr_head, node* temp1){
    if(curr_head==NULL || curr_head->next==NULL){
        return curr_head;
    }
    node *temp2=curr_head->next;
    curr_head->next=temp1;
    return reverse_recursive(temp2,curr_head);
}
bool detect_loop(node *curr_head){
    while(curr_head!=NULL || curr_head->vis==false){
        curr_head->vis=true;
        curr_head=curr_head->next;
    }
    if(curr_head==NULL){
        return false;
    }
    else{
        return true;
    }
}
bool floyd_cycle_detection(node *curr_head){
    if(curr_head==NULL){
        return false;
    }
    else{
        node *slow=curr_head;
        node *fast=curr_head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
            else continue;
        }
        return false;
    }
}

int search_node(node*head,int x){
    int pos=1;
    int a=size(head);
    while(a>0 && head->data!=x){
        head=head->next;
        ++pos;
        --a;
    }
    if (head==NULL){
        return -1;
    }
    else{
        return pos;
    }
}
node *merge_list(node*temp1, node*temp2){
    node *joint=new node(-1);
    node *org=joint;
    while(temp1!=NULL || temp2!=NULL){
        if(temp1==NULL && temp2!=NULL){
            joint->next=temp2;
            joint=temp2;
            temp2=temp2->next;
        }
        else if(temp1!=NULL && temp2==NULL){
            joint->next=temp1;
            joint=temp1;
            temp1=temp1->next;
        }
        else if(temp1->data>temp2->data){
            joint->next=temp2;
            joint=temp2;
            temp2=temp2->next;
        }
        else if(temp1->data< temp2->data){
            joint->next=temp1;
            joint=temp1;
            temp1=temp1->next;
        }
    }
    return (org->next);
}
void transverse(node *head){
    node *curr=head;
    cout<<"MY linked list :";
    while((curr)!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
int main(){
    node*head=NULL;
    int n,a;
    head=new node(10);
    head->next=new node(15);
    head->next->next=new node(12);
    head->next->next->next= new node(20);
    //head->next->next->next->next=new node(15);
    head->next->next->next->next=head->next;
    if(floyd_cycle_detection(head)==true){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    /*cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        head=sorted_insert(head,a);
        transverse(head);
    }
    head=insert_back(head,19);
    transverse(head);
    head=insert_front(head,59);
    transverse(head);
    head=reverse(head);
    transverse(head);
    for(int i=0;i<n;i++){
        cin>>a;
        head=insert_front(head, a);
        transverse(head);
    }
    head=insert_back(head,0);
    transverse(head);
    head=insert_back(head,59);
    transverse(head);
    head=delete_front(head);
    transverse(head);
    head=delete_end(head);    
    transverse(head);
    head=delete_end(head);    
    transverse(head);
    head=insert_back(head,20);
    transverse(head);
    head=delete_front(head);    
    transverse(head);
    head=insert(head,1,45);
    transverse(head);
    head=insert(head,3,31);
    transverse(head);
    head=insert(head,4,8);
    transverse(head);
    head=insert(head,2,49);
    transverse(head);
    head=insert(head,7,17);
    transverse(head);*/
    return 0;
}