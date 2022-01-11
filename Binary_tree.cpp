// BINARY TREE HAS ATMOST TWO CHILDREN IE. THEY HAVE ATMOST 2 DEGREE .
// BINARY TREE HAS TWO TYPES OF TRANSVERSALS : 1.) BREADTH FIRST TRANSVERSAL(LEVEL ORDER)
// 2.) DEPTH FIRST TRANSVERSAL 
// THERE ARE THREE TYPES OF DEPTH FIRST TRANSVERAL:
//1)INORDER TRANSVERSAL  (LEFT -> ROOT -> RIGHT)  // LEFT MEANS LEFT SUBTREE
//2)PREORDER TRANSVERSAL (ROOT -> LEFT -> RIGHT) // RIGHT MEANS RIGHT SUBTREE
//3)POSTORDER TRANSVERSAL  (LEFT -> RIGHT -> ROOT)
#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

class treenode{
    public:
    int key;
    treenode*left;
    treenode*right;
    treenode(int x){
        key=x;
        left=NULL;
        right=NULL;
    }
};

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
void nodes_at_kth_dist(treenode*root,int k){
    if(k==0){
        if(root!=NULL){
            cout<<root->key<<" ";
        }
    }
    else{
        nodes_at_kth_dist(root->left,k-1);
        nodes_at_kth_dist(root->right,k-1);
    }
}
int heightoftree(treenode *root){
    if(root==NULL){
        return 0;
    }
    else{
        return max(heightoftree(root->left),heightoftree(root->right))+1;
    }
}
void levelordertransversal_2(treenode *root){
    // time complexiety = O(n) , Auxiallary space => O(n)
    cout<<"Level order transversal :";
    if(root==NULL){
        return;
    }
    else{
        queue<treenode*> v1;
        v1.push(root);
        while(!v1.empty()){
            treenode *curr=v1.front();
            v1.pop();
            cout<<curr->key<<" ";
            if(curr->left!=NULL){
                v1.push(curr->left);
            }
            if(curr->right!=NULL){
                v1.push(curr->right);
            }
        }
        cout<<endl;
    }
}
void levelordertransversal_1(treenode *root){
    // Time complexity => O(n*h)(not a good solution)
    cout<<"Level order transversal :";
    int a=heightoftree(root);
    int p=0;
    while(p<=a){
        nodes_at_kth_dist(root,p);
        p+=1;
    }
    cout<<endl;
}
int sizeoftree(treenode *root){
    if(root==NULL){
        return 0;
    }
    else{
        return sizeoftree(root->left) + sizeoftree(root->right)+1;
    }
}
int maxelement_tree(treenode *root){
    if(root!=NULL){
        return max(root->key,max(maxelement_tree(root->left),maxelement_tree(root->right))) ;
    }
    else{
        return INT_MIN;
    }
}
void left_view_of_tree(treenode *root){
    cout<<"Left view of tree :";
    if(root==NULL){
        return ;
    }
    else{
        queue<treenode *> v1;
        v1.push(root);
        while(!v1.empty()){
            int count=v1.size();
            for(int i=0;i<count;i++){
                treenode *curr=v1.front();
                v1.pop();
                if(i==0) cout<<curr->key<<" ";
                if(curr->left!=NULL){
                    v1.push(curr->left);
                }
                if(curr->right!=NULL){
                    v1.push(curr->right);
                }
            }   
        }
        cout<<endl;
    }
}
int balancedtree(treenode *root){ 
    if(root==NULL){
        return 0;
    }
    int lt=balancedtree(root->left);
    if(lt==-1){
        return -1;
    }
    int ht=balancedtree(root->right);
    if(ht==-1){
        return -1;
    }
    if(abs(lt-ht)>1){
        return -1;
    }
    else return max(lt,ht)+1;
}
/*vector<treenode *> l1,l2;
treenode* LCA_of_tree(treenode* root,int n1,int n2){
    if(root->key==n1){
        l1.push_back(root);
    }
    if(root->key==n2){
        l2.push_back(root);
    }
    else{
        l1.push_back(root);
        l2.push_back(root);
        LCA_of_tree(root->left,n1,n2);
        LCA_of_tree(root->right,n1,n2);
    }
}*/
treenode* insert_in_tree(treenode *root,int x){  // for complete binary tree
    // time complexiety = O(n) , Auxiallary space => O(n)
    cout<<"Node inserted into binary tree :"<<x<<endl; 
    treenode *temp=new treenode(x);
    if(root==NULL){
        return temp;
    }
    else{
        treenode *curr=root;
        queue<treenode*> v1;
        v1.push(curr);
        while(!v1.empty()){
            curr=v1.front();
            v1.pop();
            if(curr->left==NULL){
                curr->left=temp;
                break;
            }
            else if(curr->right==NULL){
                curr->right=temp;
                break;
            }
            else{
                v1.push(curr->left);
                v1.push(curr->right);
            }
        }
        return root;
    }
}
treenode* delete_lastnode_in_tree(treenode* root){
    cout<<"Last node deleted from the tree "<<endl;
    if(root==NULL){
        return root;
    }
    else{
        queue<treenode*> v1;
        treenode* curr=root;
        treenode* parnode=root;
        v1.push(curr);
        while(!v1.empty()){
            treenode *curr=v1.front();
            v1.pop();
            if(curr->left!=NULL){
                parnode=curr;
                v1.push(curr->left);
            }
            if(curr->right!=NULL){
                parnode=curr;
                v1.push(curr->right);
            }
        }
        if(parnode->right!=NULL){
            delete(parnode->right);
            parnode->right=NULL;
        }
        else{
            delete(parnode->left);
            parnode->left=NULL;
        }
        return root;
    }
}
treenode * delete_any_node_in_tree(treenode* root, int x){
    cout<<"Element deleted from the tree :"<<x<<endl;
    if(root==NULL){
        return root;
    }
    else{
        queue<treenode*> v1;
        treenode* curr=root;
        treenode* parnode=root;
        treenode *temp;
        v1.push(curr);
        while(!v1.empty()){
            curr=v1.front();
            if(curr->key==x){
                temp=curr;
            }
            v1.pop();
            if(curr->left!=NULL){
                parnode=curr;
                v1.push(curr->left);
            }
            if(curr->right!=NULL){
                parnode=curr;
                v1.push(curr->right);
            }
        }
        temp->key=curr->key;
        if(parnode->right!=NULL){
            delete(parnode->right);
            parnode->right=NULL;
        }
        else{
            delete(parnode->left);
            parnode->left=NULL;
        }
        return root;
    }
}
treenode *construct_binarytree(vector<int>ir, vector<int>pr,int i, int j){
    if(i>j) return NULL;

}
int nodes_with_one_child(treenode *root){
    if(root==NULL){
        return 0;
    }
    else{
        queue<treenode*> v1;
        treenode* curr=root;
        int n=0;
        v1.push(curr);
        while(!v1.empty()){
            int count=v1.size();
            if(count=1){
                n+=1;
            }
            for(int i=0;i<count;i++){
                curr=v1.front();
                v1.pop();
                if(curr->left!=NULL){
                    v1.push(curr->left);
                }
                if(curr->right!=NULL){
                    v1.push(curr->right);
                }
            }
        }
        return (n-1);
    }
}
bool child_sum_problem(treenode* root){
    if(root==NULL){
        return true;
    }
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    int sum=0;
    if(root->left!=NULL){
        sum+=root->left->key;
    }
    if(root->right!=NULL){
        sum+=root->right->key;
    }
    return((root->key==sum) && child_sum_problem(root->left) && child_sum_problem(root->right));
}
vector<treenode*> serialize_a_tree(treenode *root){
    int i=0;
    vector<treenode*> v1;
    queue<treenode *> li;
    treenode* curr=root;
    li.push(curr);
    v1.push_back(curr);
    while(!li.empty()){
        curr=li.front();
        li.pop();
        if(curr->left==NULL){
            v1[2*i+1]=NULL;
        }
        else{
            li.push(curr->left);
            v1[2*i+1]=curr->left;
        }
        if(curr->right==NULL){
            v1[2*i+2]=NULL;
        }
        else{
            li.push(curr->right);
            v1[2*i+2]=curr->right;
        }
        i+=1;
    }
    return v1;
}
treenode* deserialize_a_vector(vector<treenode*> tp){
    treenode *curr=tp[0];
    for(int i=0;i<tp.size();i++){
        if(tp[i]!=NULL){
            tp[i]->left=tp[2*i+1];
            tp[i]->right=tp[2*i+2];
        }
    }
    return tp[0];
}
//-------------------------------------------------------------------------
//          5
//        /   '\'
//       7     11
//      / \   /  '\'
//     2   4 1    6

//Inorder=> 2 7 4 5 1 11 6 
//Preorder=> 5 7 2 4 11 1 6    
// Postorder=> 2 4 7 1 6 11 5
//---------------------------------------------------------------------------
int main(){
    treenode *root=NULL; 
    int n,a;
    //root=new treenode(5);
    //root->left=new treenode(7);
    //root->left->left=new treenode(11);
    //root->left->right=new treenode(4);
    //root->right->left=new treenode(1);
    //levelordertransversal_2(root);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        root=insert_in_tree(root,a);
        levelordertransversal_2(root);
    }
    delete_any_node_in_tree(root,6);
    levelordertransversal_2(root);
    cout<<"Inorder trasversal :";
    inorder_transversal(root);
    cout<<"\n";
    cout<<"preorder trasversal :";
    preorder_transversal(root);
    cout<<"\n";
    cout<<"postorder trasversal :";
    postorder_transversal(root);
    cout<<"\n";
    //cout<<"nodes at kth distance :";
    //nodes_at_kth_dist(root,0);
    //cout<<"\n";
    cout<<"Height of tree :"<<heightoftree(root)<<endl;
    levelordertransversal_2(root);
    cout<<"Size of tree :"<<sizeoftree(root)<<endl;
    cout<<"Max element :";
    cout<<maxelement_tree(root)<<endl;
    left_view_of_tree(root);
    vector<treenode*> pi=serialize_a_tree(root);
    treenode *temp=deserialize_a_vector(pi);
    levelordertransversal_2(temp);
    return 0;
}