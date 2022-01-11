// BST IMPLEMENTATION
// BINARY SEARCH TREE CAN BE SUCCESFULLY BUILT FROM POSTORDER OR INORDER TRANSVERSAL
// SINCE ITS INORDER TRANSVERSAL IS IN  INCREASING ORDER(SORTED) ALWAYS
#include<bits/stdc++.h>
#include<stack>
#include<vector>
using namespace std;

class treenode{
    public:
    int key;
    treenode* left;
    treenode* right;
    treenode(int x){
        key=x;
        left=NULL;
        right=NULL;
    }
};

class BST{
    public:
    treenode *root;
    BST(){
        root=NULL;
    }

    void inorder_transversal(treenode *root){
        if(root!=NULL){
            inorder_transversal(root->left);
            cout<<root->key<<" ";
            inorder_transversal(root->right);
        }
        else{
            return;
        }
    }
    void preorder_transversal(treenode *root){
        if(root!=NULL){
            cout<<root->key<<" ";
            preorder_transversal(root->left);
            preorder_transversal(root->right);
        }
        else{
            return;
        }
    }
    void postorder_transversal(treenode *root){
        if(root!=NULL){
            postorder_transversal(root->left);
            postorder_transversal(root->right);
            cout<<root->key<<" ";
        }
        else{
            return;
        }
    }
    void levelordertransversal(treenode *curr_root){
        // time complexiety = O(n) , Auxiallary space => O(n)
        cout<<"Level order transversal :";
        if(curr_root==NULL){
            return;
        }
        else{
            queue<treenode*> v1;
            v1.push(curr_root);
            while(!v1.empty()){
                treenode *temp=v1.front();
                v1.pop();
                cout<<temp->key<<" ";
                if(temp->left!=NULL){
                    v1.push(temp->left);
                    }
                if(temp->right!=NULL){
                    v1.push(temp->right);
                }
            }
            cout<<endl;
        }
    }
    bool search_in_BST(treenode *root,int x){
        if(root==NULL){
            cout<<"Element "<<x<<" is not present in BST "<<endl;
            return false;
        }
        else{
            if(root->key>x){
                search_in_BST(root->left,x);
            }
            else if(root->key<x){
                search_in_BST(root->right,x);
            }
            else{
                cout<<"Element "<<x<<" is present in BST"<<endl;
                return true;
            }
        }
    }
    void insert_in_BST(treenode *curr_root,int x){
        treenode *temp=new treenode (x);
        if(curr_root==NULL){
            cout<<"Element "<<x<<" is inserted into BST"<<endl;
            this->root=temp;
        }
        else{
            treenode *parnode=curr_root;
            while(curr_root!=NULL){
                if(curr_root->key>x){
                    parnode=curr_root;
                    curr_root=curr_root->left;                        
                }
                else if(curr_root->key==x){
                    parnode=curr_root;
                    break;
                }
                else{
                    parnode=curr_root;
                    curr_root=curr_root->right;
                }
            }
            if(parnode->key==x){
                cout<<"Element is present already in BST"<<endl;
            }
            else if(parnode->key>x){
                cout<<"Element "<<x<<" is inserted in BST"<<endl;
                parnode->left=temp;
            }
            else{
                cout<<"Element "<<x<<" is inserted into BST"<<endl;
                parnode->right=temp;
            }
        }
    }
    treenode* leftmost_rtsubtree(treenode *gen){
        gen=gen->right;
        while(gen!=NULL && gen->left!=NULL){
            gen=gen->left;
        }
        return gen;
    } 
    treenode* delete_in_BST(treenode *curr_root,int x){
        if(curr_root==NULL){
            return root;
        }
        else if(curr_root->key>x){
            curr_root->left=delete_in_BST(curr_root->left,x);
        }
        else if(curr_root->key<x){
            curr_root->right=delete_in_BST(curr_root->right,x);
        }
        else{
            if(curr_root->left==NULL){
                treenode *temp=curr_root->right;
                delete(curr_root);
                return temp;
            }
            else if(curr_root->right==NULL){
                treenode *temp=curr_root->left;
                delete(curr_root);
                return temp;
            }
            else{
                treenode *temp=leftmost_rtsubtree(curr_root);
                curr_root->key=temp->key;
                curr_root->right=delete_in_BST(curr_root->right,temp->key);
            }
        }
        return curr_root;
    }
    treenode* bst_from_preorder(vector<treenode*> li){
        stack<treenode*> v1;
        treenode* pp= new treenode(-10000);
        v1.push(pp);
        treenode* point=NULL;
        for(int i=0;i<li.size();i++){
            if(i==0){
                point=li[i];
            }
            else{
                if(li[i]->key<point->key){
                    v1.push(li[i]);
                    point->left=li[i];
                    point=li[i];
                }
                else if(li[i]->key>point->key){
                    if(li[i]->key<v1.top()->key){
                        point->right=li[i];
                        point=li[i];
                    }
                    else{
                        point=v1.top();
                        v1.pop();
                        i=i-1;
                    }
                }
            }
        }
        return li[0];
    }
    treenode *floor_in_bst(treenode *curr_root,int x,treenode *parnode){
        if(curr_root==NULL){
            if(parnode==NULL){
                cout<<"No such floor value is present "<<endl;
            }
            return parnode;
        }
        else{
            if(curr_root->key>x){
                floor_in_bst(curr_root->left,x,parnode);
            }
            else if(curr_root->key<x){
                parnode=curr_root;
                floor_in_bst(curr_root->right,x,parnode);
            }
            else{
                return parnode;
            }
        }
    }

    treenode *ceil_in_bst(treenode*curr_root,int x, treenode* parnode){
        if(curr_root==NULL){
            if(parnode==NULL){
                cout<<"No such ceil value is present "<<endl;
            }
            return parnode;
        }
        else{
            if(curr_root->key>x){
                parnode=curr_root;
                ceil_in_bst(curr_root->left,x,parnode);
            }
            else if(curr_root->key<x){
                ceil_in_bst(curr_root->right,x,parnode);
            }
            else{
                return parnode;
            }
        }
    }
    void inorder_sorted(treenode *genode,treenode*& temp){
        if(genode==NULL){
            return ;
        }
        else{
            inorder_sorted(genode->left,temp);
            temp->left=NULL;
            temp->right=genode;
            temp=genode;
            inorder_sorted(genode->right,temp);
        }
    }
    treenode* conv_in_sorted_tree(treenode *curr_root){
        treenode* temp=new treenode(-1);
        treenode *org=temp;
        inorder_sorted(curr_root,temp);
        temp->left=NULL;
        temp->right=NULL;
        
        return (org->right);
    }
    private:
    void find_nodes(treenode *curr_root,treenode *first, treenode* second,treenode*prev){
        if(curr_root !=NULL){
            swap_nodes(curr_root->left,first,second,prev);
            if(prev!=NULL && curr_root->key<prev->key){
                if(first==NULL){
                    first=prev;
                }
                second=curr_root;
            }
            prev=curr_root;
            swap_nodes(curr_root->right,first,second,prev);
        }
    }
    public:
    void swap_nodes(treenode *curr_root,treenode *first, treenode*second,treenode*prev){
        find_nodes(curr_root,first,second,prev);
        swap(first,second);
    }
};
int main(){
    BST nvg;
    nvg.root=NULL;
    //nvg.root->left=new treenode(5);
    //nvg.root->right=new treenode(20);
    //nvg.root->left->left=new treenode(3);
    //nvg.root->right->left=new treenode(18);
    //nvg.root->right->right=new treenode(80);
    //nvg.root->right->left->left=new treenode(16);
    int n,a,d;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        nvg.insert_in_BST(nvg.root,a);
        nvg.levelordertransversal(nvg.root);
    }
    //nvg.search_in_BST(nvg.root,3);
    cout<<"INORDER TRANSVERSAL :";
    nvg.inorder_transversal(nvg.root);
    cout<<"\n";
    cin>>d;
    //cout<<"Element "<<d<<" deleted from BST "<<endl;
    //nvg.root=nvg.delete_in_BST(nvg.root,d);
    //nvg.levelordertransversal(nvg.root);
    cout<<(nvg.ceil_in_bst(nvg.root,d,NULL))->key<<endl;
    //nvg.root=nvg.conv_in_sorted_tree(nvg.root);
    //nvg.levelordertransversal(nvg.root);
    nvg.swap_nodes(nvg.root,NULL,NULL,NULL);
    nvg.levelordertransversal(nvg.root);
    return 0;
}