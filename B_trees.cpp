//1)B TREES ARE SELF BALANCING BINARY SEARCH TREES LIKE AVL TREE , RED-BLACK TREES ETC.
//2)2-3 AND 2-3-4 TREE OF ORDER(DEGREEE) 3 AND 4 RESPECTIVELY ARE THE MOST COMMON TREES 
//  IN B-TREES.
//3)B TREES ARE MULTIWAY SEARCH TREES AND HAVE ALL LEAF NODES AT SAME LEVEL.
//4)FOR A GENERAL B TREE EACH NODE HAVE  ceil(d/2) CHILDREN(atleast) WHERE d IS DEGREE.
//5)2-3 AND 2-3-4 TREES HAVE ATMOST 3 CHILDREN .
//-------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
// 2-3 TREE CODE
class treenode{
    int ltkey;
    int rtkey;
    treenode*left;
    treenode*middle;
    treenode*right;
    treenode(int x){
        ltkey=x;
        rtkey=NULL;
        left=NULL;
        middle=NULL;
        right=NULL;
    }
};

 