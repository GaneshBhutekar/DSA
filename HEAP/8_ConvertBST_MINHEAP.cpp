#include<iostream>
#include<vector>
#include<queue>


/*
    convert the BST into the min heap

    DECRIPTION:
        Given a binary search tree which is also a complete binary tree.
        The problem is to convert the given BST into a Min Heap with the condition that all the values in 
        the left subtree of a node should be less than all the values in the right subtree of the node.
        This condition is applied to all the nodes, in the resultant converted Min Heap.
    time complexity : O(N)
    Space complexity : O(N)
*/

class Node{
    public:
    int data;
    ListNode* left;
    ListNode* right;
    Node(int data){
        this->data = data;
        this->right = nullptr;
        this->left = nullptr;

    }
};


void printTree(ListNode* root){
    std::queue<ListNode*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        ListNode* demo = q.front();
        q.pop();
        if(demo == nullptr){
            std::cout<<std::endl;
            if (!q.empty()){
                q.push(nullptr);

            }

        }
        else{
            std::cout<<demo->data<<" ";
            if (demo->left){
                q.push(demo->left);
            }
            if (demo->right){
                q.push(demo->right);
            }
        }
    }
}

ListNode* CreateTree(ListNode* root){
    // take the data
    int data;
    std::cout<<"enter the data"<<std::endl;
    std::cin>>data;
    if (data == -1){
        return nullptr;
    }
    root = new Node(data);
    // go to the left 
    root->left = CreateTree(root->left);
    // go to the right
    root->right = CreateTree(root->right);
    return root;
}

void InorderTraversal(ListNode* root,std::vector<int> &sorted){ //O(N)
    if (root== nullptr){
        return;
    }

    // move left most 
    InorderTraversal(root->left,sorted);

    sorted.push_back(root->data);

    // move right
    InorderTraversal(root->right,sorted);

}


void replace_element(ListNode* &root,std::vector<int> sorted,int &index){ // O(N)
    if (root==nullptr){
        return;
    }
    // first push element then move left till null
    root->data = sorted[index];
    index++;
    replace_element(root->left,sorted,index);

    // then go right
    replace_element(root->right,sorted,index);
}
ListNode* ConvertBstToMinHeap(ListNode* root){
    // we know that our node should be smaller than left and left should be smaller than right
    // this order is similar to the preorder so if i have sorted list then first element goes to node 
    // then second element goes to left and the third element goes to right And sorted means inorder 
    // so find inorder
    std::vector<int> sorted;
    InorderTraversal(root,sorted);
    for(int i : sorted){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    // now we will replace this element in preorder in same structure of BST because it is complete binary search tree
    int index = 0;
    replace_element(root,sorted,index);
    return root;
}

int main(){
    ListNode* root = nullptr;
    root = CreateTree(root);
    // 16 8 6 1 -1 -1 7 -1 -1 11 -1 -1 20 19 -1 -1 25 -1 -1
    printTree(root);
    std::cout<<"after converting BST to min heap:"<<std::endl;
    root=ConvertBstToMinHeap(root);

    printTree(root);


}