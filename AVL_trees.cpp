//IMPLEMENTING AVL TREE
//AVL TREE IS PERFECT BALANCED BINARY SEARCH TREE
//INSERTION HAS 4 TYPES OF ROTATIONS:
//1)LL ROTATION :IF LEFT SIDE OF UNBALANCED(=2) NODE HAS B.F.= 1
//2)LR ROTATION :IF LEFT SIDE OF UNBALANCED(=2) NODE HAS B.F.= -1
//3)RR ROTATION :IF RIGHT SIDE OF UNBALANCED(=-2) NODE HAS B.F.= 1
//4)RL ROTATION :IF RIGHT SIDE OF UNBALANCED(=-2) NODE HAS B.F.= -1
//--------------------------------------------------------------------------------
//DELETION HAS  6 TYPES OF ROATATIONS:
//IF AFTER DELETION FROM RIGHT SIDE , CURRENT NODE BECOMES UNBALANCED(LEFT SIDE) :
//L1 ROTATION (LL ROTATION), IF LEFT CHILD OF CURRENT NODE HAS B.F.= 1
//L-1 ROTATION (LR ROTATION), IF LEFT CHILD OF CURRENT NODE HAS B.F.= -1
//L0 ROTATION (LL OR LR ROTATION), IF LEFT CHILD OF CURRENT NODE HAS B.F.= 0
//---------------------------------------------------------------------------------
//IF AFTER DELETION FROM LEFT SIDE , CURRENT NODE BECOMES UNBALANCED(RIGHT SIDE) :
//R1 ROTATION (RR ROTATION), IF RIGHT CHILD OF CURRENT NODE HAS B.F.= 1
//R-1 ROTATION (RL ROTATION), IF RIGHT CHILD OF CURRENT NODE HAS B.F.= -1
//R0 ROTATION (RR OR RL ROTATION), IF RIGHT CHILD OF CURRENT NODE HAS B.F.= 0
//---------------------------------------------------------------------------------
// TIME COMPLEXIETY(SEARCH,INSERT,DELETION,FLOOR,CEIL IN AVL TREE = LOG(N))
//---------------------------------------------------------------------------------

//INTERSTING FACTS ABOUT AVL TREE:
//1.)IF HEIGHT IS GIVEN , THEN MIN AND MAX NODES REQUIRED FOR AVL TREE TO BE BALANCED :
//                {          0   ,     IF h=0   } 
//   MIN NODES(n)={          1   ,     IF h=1   }
//                { n(h-2) + n(h-1) + 1 ,IF h>=2}
//
//   MAX NODES(n)=  2^(h)-1 
//-------------------------------------------------------------------------------------
//2.) IF NODES(n) ARE GIVEN , THEN AVL TREE HAS MINIMUM HEIGHT AS : log(n+1) base to 2 
//3.) IF NODES(n) ARE GIVEN , THEN AVL TREE HAS MAX HEIGHT AS :1.44*log(n+2) base to 2 
//4.) AVL TREES ARE BELIEVED TO BE BALANCED DUE TO THE REASON THAT THERE MINUMUM NODES
//    REQUIRED FOR THE TREE TO BE BALANCED RESEMBELS THE FIBONACCI SERIES SEQUENCE AND
//    THIS SEQUENCE BELIEVED TO BE A BALANCED SERIES.
//5.) IN FIBONAACI SERIES:  f(i+1)/f(i) = 1.6 (approx.) after 4
//------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

class treenode{
    public:
    int key;
    treenode* left;
    treenode* right;
    int height;
    treenode(int x){
        key=x;
        height=1;
        left=NULL;
        right=NULL;
    }
};

class AVL{
    public:
    treenode*root;
    AVL(){
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
    bool search_in_AVL(treenode *root,int x){
        if(root==NULL){
            cout<<"Element "<<x<<" is not present in AVL "<<endl;
            return false;
        }
        else{
            if(root->key>x){
                search_in_AVL(root->left,x);
            }
            else if(root->key<x){
                search_in_AVL(root->right,x);
            }
            else{
                cout<<"Element "<<x<<" is present in AVL "<<endl;
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
    treenode *insertion_rotations_in_avl( treenode* curr_root){
        cout<<"AVL TREE BECOMES UNBALANCED ! "<<endl;
        if(balancefactor(curr_root)>=2 && balancefactor(curr_root->left)==1){            
            cout<<"LL ROTATION TAKES PLACE "<<endl;
            treenode *temp=curr_root->left->right;
            treenode *var=curr_root->left;
            var->right=curr_root;
            curr_root->left=temp;
            var->height=height_of_node(var);
            var->right->height=height_of_node(var->right);
            return var;
        }
        else if(balancefactor(curr_root)>=2 && balancefactor(curr_root->left)==-1){
            cout<<"LR ROTATION TAKES PLACE "<<endl;
            treenode *var=curr_root->left->right;
            treenode *temp=curr_root->left;
            treenode *l1=var->left;
            treenode *l2=var->right;
            var->left=temp;
            var->right=curr_root;
            temp->right=l1;
            curr_root->left=l2;
            var->height=height_of_node(var);
            var->right->height=height_of_node(var->right);
            temp->height=height_of_node(temp);
            return var;
        }
        else if(balancefactor(curr_root)<=-2 && balancefactor(curr_root->right)==-1){
            cout<<"RR ROTATION TAKES PLACE "<<endl;
            treenode *temp=curr_root->right->left;
            treenode *var=curr_root->right;
            var->left=curr_root;
            curr_root->right=temp;
            var->height=height_of_node(var);
            var->left->height=height_of_node(var->left);
            var->height=height_of_node(var);
            var->left->height=height_of_node(var->left);
            return var;
        }
        else if(balancefactor(curr_root)<=-2 && balancefactor(curr_root->right)==1){
            cout<<"RL ROTATION TAKES PLACE "<<endl;
            treenode *var=curr_root->right->left;
            treenode *temp=curr_root->right;
            treenode *l1=var->left;
            treenode *l2=var->right;
            var->right=temp;
            var->left=curr_root;
            temp->left=l2;
            curr_root->right=l1;
            var->height=height_of_node(var);
            var->right->height=height_of_node(var->right);
            temp->height=height_of_node(temp);
            return var;
        }
    }

    treenode *deletion_rotations_in_AVL(treenode*curr_root){
        if(balancefactor(curr_root)==2 && balancefactor(curr_root->left)==1){
            cout<<"L1 ROTATIONS TAKES PLACE "<<endl;
            return insertion_rotations_in_avl(curr_root);
        }
        else if(balancefactor(curr_root)==2 && balancefactor(curr_root->left)==-1){
            cout<<"L-1 ROTATION TAKES PLACE "<<endl;
            return insertion_rotations_in_avl(curr_root);
        }
        else if(balancefactor(curr_root)==-2 && balancefactor(curr_root->right)==-1){
            cout<<"R-1 ROTATION TAKES PLACE "<<endl;
            return insertion_rotations_in_avl(curr_root);
        }
        else if(balancefactor(curr_root)==-2 && balancefactor(curr_root->right)==1){
            cout<<"R1 ROTATION TAKES PLACE "<<endl;
            return insertion_rotations_in_avl(curr_root);
        }
        else if(balancefactor(curr_root)==2 && balancefactor(curr_root->left)==0){
            cout<<"L0 ROTATION TAKES PLACE "<<endl;
            treenode *temp=curr_root->left->right;
            treenode *var=curr_root->left;
            var->right=curr_root;
            curr_root->left=temp;
            var->height=height_of_node(var);
            var->right->height=height_of_node(var->right);
            return var;
        }
        else if(balancefactor(curr_root)==-2 && balancefactor(curr_root->left)==0){
            cout<<"R0 ROTATION TAKES PLACE "<<endl;
            treenode *temp=curr_root->right->left;
            treenode *var=curr_root->right;
            var->left=curr_root;
            curr_root->right=temp;
            var->height=height_of_node(var);
            var->left->height=height_of_node(var->left);
            var->height=height_of_node(var);
            var->left->height=height_of_node(var->left);
            return var;
        }
    }
    public:
    treenode* insert_in_AVL(treenode*curr_root, int x){
        if(curr_root==NULL){
            treenode *temp=new treenode(x);
            return temp;
        }
        else{
            if(curr_root->key>x){
                curr_root->left =insert_in_AVL(curr_root->left,x);
            }
            else if(curr_root->key<x){
                curr_root->right= insert_in_AVL(curr_root->right,x);
            }
            curr_root->height=height_of_node(curr_root);
            int k=balancefactor(curr_root);
            if(k>1 || k<-1){
                curr_root=insertion_rotations_in_avl(curr_root);
            }
            return curr_root;
        }
    }
    treenode *delete_in_AVL(treenode * curr_root,int x){
        if(curr_root==NULL){
            return curr_root;
        }
        else if(curr_root->key>x){
            curr_root->left=delete_in_AVL(curr_root->left,x);
        }
        else if(curr_root->key<x){
            curr_root->right=delete_in_AVL(curr_root->right,x);
        }
        else{
            if(curr_root->left==NULL){
                treenode* temp=curr_root->right;
                delete(curr_root);
                return temp;
            }
            else if(curr_root->right==NULL){
                treenode* temp=curr_root->left;
                delete(curr_root);
                return temp;
            }
            else{
                treenode *genode=curr_root->right;
                while(genode!=NULL && genode->left!=NULL){
                    genode=genode->left;
                }
                curr_root->key=genode->key;
                curr_root->right=delete_in_AVL(curr_root->right,genode->key);
            }
        }
        // code for checking balancing
        curr_root->height=height_of_node(curr_root);
        int k=balancefactor(curr_root);
        if(k>1 || k<-1){
            curr_root=deletion_rotations_in_AVL(curr_root);
        }
        return curr_root;
    }
};

int main(){
    AVL nvg;
    int n,a,d;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        cout<<"Element inserted in Avl tree :"<<a<<endl;
        nvg.root=nvg.insert_in_AVL(nvg.root,a);
        nvg.levelordertransversal(nvg.root);
    }
    cin>>d;
    for(int i=0;i<d;i++){
        cin>>a;
        cout<<"Element to be deleted from AVL Tree :"<<a<<endl;
        nvg.root=nvg.delete_in_AVL(nvg.root,a);
        nvg.levelordertransversal(nvg.root);
    }
    return 0;
}