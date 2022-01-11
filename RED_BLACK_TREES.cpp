#include<bits/stdc++.h>
using namespace std;

class treenode{
    public:
    int key;
    treenode*left;
    treenode*right;
    treenode*parent;
    string color;
    treenode(int x){
        key=x;
        color="red";
        left=NULL;
        right=NULL;
        parent=NULL;
    }
};

class red_black_tree{
    public:
    treenode* root;
    red_black_tree(){
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
        cout<<"LEVEL ORDER TRANSVERSAL :";
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
    bool search_in_Red_Black_Tree(treenode *root,int x){
        if(root==NULL){
            cout<<"Element "<<x<<" is not present in Red Black tree "<<endl;
            return false;
        }
        else{
            if(root->key>x){
                search_in_Red_Black_Tree(root->left,x);
            }
            else if(root->key<x){
                search_in_Red_Black_Tree(root->right,x);
            }
            else{
                cout<<"Element "<<x<<" is present in Red Black Tree"<<endl;
                return true;
            }
        }
    }
    int height_of_node(treenode *curr_root){
        if(curr_root==NULL){
            return 0;
        }
        else{
            int lt=height_of_node(curr_root->left);
            int ht=height_of_node(curr_root->right);
            return (max(lt,ht)+1);
        }
    }
    private:
    int balancefactor(treenode *curr_root){
        if(curr_root==NULL){
            return 0;
        }
        else{
            int lt=height_of_node(curr_root->left);
            int rt=height_of_node(curr_root->right);
            return (lt-rt);
        }
    }

    treenode* insertion_in_Red_Black_tree(treenode *curr_root ,int x){
        if(curr_root==NULL){
            treenode*temp=new treenode(x);
            return temp;
        }
        else{
            if(curr_root->key>x){
                curr_root->left=insertion_in_Red_Black_tree(curr_root->left,x);
            }
            else if(curr_root->key<x){
                curr_root->right=insertion_in_Red_Black_tree(curr_root->right,x);
            }
            if(curr_root->color=="red"){

            } 
        }
    }
};