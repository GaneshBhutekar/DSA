#include<iostream>
#include<vector>


// need heapify 
void heapify(std::vector<int> &a, int n,int element){

    // add it
    a.push_back(element);
    n++;
    // now place it on correct way
    int index = n-1;
    while(index != 0){
        int parent = (index-1)/2;
        // check is parent is smaller or not
        if (a[parent] < a[index]){
            /// then replace it
            std::swap(a[parent],a[index]);
            index = parent;
        }
        else{
            return;
        }
    }
    return;
}
std::vector<int> mergeHeap(std::vector<int> &a,std::vector<int> &b,int n,int m){
    // nnow insert one elments to another
    for(int i =0;i<m;i++){
        heapify(a,n,b[i]);
        n++;
    }
    std::cout<<std::endl;
    return a;
}

void print(std::vector<int> a){
    for(int i : a){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    std::vector<int> a = {10};
    std::vector<int> b = {12};
    int n =a.size();
    int m = b.size();
    std::vector<int> ans = mergeHeap(a,b,n,m);
    print(ans);
    
}