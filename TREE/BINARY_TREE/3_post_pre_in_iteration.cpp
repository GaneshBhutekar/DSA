/* my active hours will 
1. 14:00 to 19:00

2. 12:00 to 4:30 to 5:00
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class node{
    public:
    int data;
    node* right;
    node* left;
    node(int data){
        this->data = data;
        this->right=NULL;
        this->left = NULL;

    }


};

node* buildtree(node * &root){
    int data;
    cout<<"enter the element "<<endl;
    cin>> data;

    if (data == -1){
        return NULL;
    }

    root = new node(data);

    // for the left side
    cout<<"for left "<<endl;
    root->left = buildtree(root->left);

    // for right    
    cout<<"for right "<<endl;
    root->right = buildtree(root->right);
    return root;
}
// do in pre post in iteration.

void inorder(node*root){
    // need stack for traversal
    stack<node*> st;

    node*current = root;

    // now iterate over till all the nodes are'nt covered.
    while(current != NULL || !st.empty()){

        // iterate to the left 
        while(current != NULL){
            st.push(current);
            current = current ->left;
        }

        // now deal with the last left node
        current = st.top();
        st.pop();

        //print the current.
        cout<<current->data<<" ";

        // because it is last now go to right 

        current = current->right; // just one time in inorder because here legft dominate 

    }
    cout<<endl;
}


void preorder(node* root){
    stack<node*> st;

    node* current = root;

    // traverse till all noe printed
    while(current != NULL || !st.empty()){

        // iterate to every node and print it and then left.
        while(current != NULL){
            cout<<current->data <<" ";
            st.push(current);
            current= current->left;
        }

        // when it  is NULL move to right of the top of the stack and pop that top also 
        current = st.top();
        st.pop();

        // shift to right 
        current = current ->right;

    }
    cout<<endl;
}
// to do postorder which is LRN we have to do NRL and then reverse it so we need 2 stack

void postorder(node* root){
    // first do NRL

    stack<node*> st;
    stack<node*> reverse;

    node*current = root;
    while(current != NULL || !st.empty()){

        // iterate right continuosly
        while(current != NULL){
            st.push(current);
            reverse.push(current);
            current=current->right;
        }

        current = st.top();
        st.pop();

        current = current ->left;
        
    }

    // now stack reverse has reversed answer which we will display
    while(!reverse.empty()){
        cout<<reverse.top()->data<<" ";
        reverse.pop();
    }
    cout<<endl;
}


int main(){
    node* root = NULL;
    buildtree(root);

    cout<<"inorder traversal"<<endl;
    inorder(root);
    cout<<"pre-order traversal"<<endl;
    preorder(root);
    cout<<"postorder traversal "<<endl;
    postorder(root);

}