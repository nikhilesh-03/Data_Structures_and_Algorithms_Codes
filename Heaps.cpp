//1)Heaps are the complete binary tree structures,mostly are perfectly binary trees.
//2)Heaps array's form must not have any NULL value in their represntation.ie. Each 
//   node(i) and its children (2*i+1 and 2*i+2) must not be NULL.
//3) TWO TYPES OF HEAPS ARE THERE:
//  1.)MAX HEAP: EACH NODE OF THIS HEAP HAVE KEY VALUE GREATER THAN OR EQUAL TO ITS
//     DESCENDERS.
//  2.)MIN HEAP: EACH NODE OF THIS HEAP HAVE KEY VALUE LESSER THAN OR EQUAL TO ITS
//     DESCENDERS.
//4)MAX NO. OF NODES AT A GIVEN HEIGHT h => ceil(n/2^(h+1)), where n is no. of Nodes.
// IN BINARY HEAPS.

#include<bits/stdc++.h>
#include<vector>
using namespace std;

class heaps{
    public:
    int size;
    vector<int> li;
    heaps(void){
        size=0;
    }
    int left(int i){
        return (2*i+1);
    }
    int right(int i){
        return (2*i+2);
    }
    int parent(int i){
        return((i-1)/2);
    }
    int getmin_minheap(){
        return li[0];
    }
    void decrease_key_minheap(int i, int x){
        if(i==0){
            return;
        }
        else{
            li[i]=x;
            while(i>0 && li[i]<li[parent(i)]){
                swap(li[i],li[parent(i)]);
                i=parent(i);
            }
        }
    }
    void extract_min(){
        int k=li[0];
        li[0]=li[size-1];
        li.pop_back();
        size-=1;
        int index=0;
        int smaller=index;
        while(index<size){
            if(left(index)<size && li[left(index)]<li[index]){
                smaller=left(index);
            }
            if(right(index)<size && li[right(index)]<li[smaller]){
                smaller=right(index);
            }
            if(smaller!=index){
                swap(li[index],li[smaller]);
                index=smaller;
            }
            else{
                break;
            }
        }
        if(size>=0){
            cout<<"The extracted element :" <<k<<endl;
        }
    }
    
    void insert_minheap(int x){
        cout<<"Element "<<x<<" is inserted in minheap "<<endl;
        size+=1;
        li.push_back(x);
        int index=size-1;
        while(index>0 && li[index]<li[parent(index)]){
            swap(li[index],li[parent(index)]);
            index=parent(index);
        }
    }
    void insert_maxheap(int x){
        cout<<"Element "<<x<<" is inserted in maxheap "<<endl;
        size+=1;
        li.push_back(x);
        int index=size-1;
        while(index>0 && li[index] > li[parent(index)]){
            swap(li[index],li[parent(index)]);
            index=parent(index);
        }
    }
    void delete_minheap(int i){
        decrease_key_minheap(i,INT_MIN);
        extract_min();
    }

    vector<int> heap(vector<int> v1){
        int kp=v1.size();
        for(int i=(kp-2)/2; i>=0;i--){
            int index=i;
            int smaller=index;
            while(index<size){
                if(left(index)<size && v1[left(index)]<v1[index]){
                    smaller=left(index);
                }
                if(right(index)<size && v1[right(index)]<v1[smaller]){
                    smaller=right(index);
                }
                if(smaller!=index){
                    swap(v1[index],v1[smaller]);
                    index=smaller;
                }
                else{
                    break;
                }
            }
        }
        return v1;
    }
    vector<int> heap_sort(){
        int count=size;
        for(int i=0;i<count;i++){
            int k=li[0];
            li[0]=li[size-1];
            li.pop_back();
            size-=1;
            li[size]=k;
            int index=0;
            int smaller=index;
            while(index<size){
                if(left(index)<size && li[left(index)]<li[index]){
                    smaller=left(index);
                }
                if(right(index)<size && li[right(index)]<li[smaller]){
                    smaller=right(index);
                }
                if(smaller!=index){
                    swap(li[index],li[smaller]);
                    index=smaller;
                }
                else{
                    break;
                }
            }    
        }     
    }
};

int main(){
    int n,a;
    cin>>n;
    heaps nvg;
    for(int i=0;i<n;i++){
        cin>>a;
        nvg.insert_maxheap(a);
    }
    //nvg.insert_minheap(20);
    //nvg.insert_minheap(12);
    //nvg.insert_minheap(7);
    //nvg.insert_minheap(31);
    //nvg.insert_minheap(9);
    //nvg.insert_minheap(15);
    //nvg.insert_minheap(25);
    //nvg.extract_min();
    //nvg.decrease_key_minheap(4,3);
    cout<<nvg.li[nvg.left(0)]<<" "<<nvg.li[nvg.right(0)]<<endl;
    //nvg.extract_min();
    return 0;
}