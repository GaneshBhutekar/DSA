

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    ListNode* right;
    ListNode* left;
    Node(int data){
        this ->data = data;
        this ->right = NULL;
        this -> left = NULL;
    }
};


ListNode* buildtree(ListNode* &root){
    int data;
    cout<<"enter the data "<<endl;
    cin>> data;

    if (data == -1){
        return NULL;
    }

    root = new Node(data);

    // to the left
    cout<<"for left"<<endl;
    root->left = buildtree(root->left);
    cout<<"for right"<<endl;
    root->right = buildtree(root->right);
    return root;

}


void printing(deque<int> &dq, bool right_direction){
    if (right_direction){
        while(!dq.empty()){
            cout<<dq.front()<< " ";
            dq.pop_front();
        }
    }
    else{
        while(!dq.empty()){
            cout<<dq.back()<<" ";
            dq.pop_back();
        }
    }
}




void zig_zag_traverse(ListNode* root){
    if (root == NULL){
        return;
    }

    // for track 
    queue<ListNode*> q;

    // for print in reverse and non reverse.
    deque<int> dq;

    // direction
    bool right_direction=false;

    q.push(root);
    q.push(NULL);
    dq.push_back(root->data);
    printing(dq,right_direction);

    while(!q.empty()){
        ListNode* demo = q.front();
        q.pop();
        if (demo == NULL){
            printing(dq,right_direction);
            right_direction = !right_direction;
            if (!q.empty()){
                q.push(NULL);
            }

        }

        else{
            if (demo->left != NULL){
                dq.push_back(demo->left->data);
                q.push(demo->left);
            }
            if (demo->right != NULL){
                dq.push_back(demo->right->data);
                q.push(demo->right);
            }
        }


    }

    
}
void print(ListNode* root){
    queue<ListNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        ListNode* temp  = q.front();
        q.pop();

        if (temp == NULL){
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
        }
        }

        else{
            cout<<temp->data << " ";
            if (temp->left != NULL){
                q.push(temp-> left);
            }
            if (temp->right != NULL){
                q.push(temp->right);
            }
        }

    }    
}
int main(){
    ListNode* root = NULL;
    buildtree(root);
    print(root);
    zig_zag_traverse(root);
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1 


}


