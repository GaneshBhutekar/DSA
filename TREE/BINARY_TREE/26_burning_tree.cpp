#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<map>

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


void print_tree(ListNode* root){
    if (root == NULL){
        return;
    }

    queue<ListNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        ListNode* temp = q.front();
        q.pop();
        if (temp == NULL){
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if (temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

ListNode* findparents(ListNode* root, unordered_map<ListNode*,ListNode*> &parents,int target){
    ListNode* target_add = NULL;
    queue<ListNode*> q;
    q.push(root);
    parents[root] = NULL;
    while(!q.empty()){
        ListNode* demo = q.front();
        q.pop();
        if (demo->data == target){
            target_add = demo;
        }
        if (demo->left){
            parents[demo->left] = demo;
            q.push(demo->left);
        }
        if (demo->right){
            parents[demo->right] = demo;
            q.push(demo->right);
        }
    }

    return target_add;
}

int time_to_burn(ListNode* add,unordered_map<ListNode*,ListNode*> parents){

    queue<ListNode*> q; // for traversal

    unordered_map<ListNode*,bool> visited; // check for visited 
    int time = 0;
    q.push(add);
    visited[add] = true;
    while(!q.empty()){
        // clear the queue and burn there area at that time and then increase time by 1.
        int mysize = q.size();
        bool flag = false;
        for(int i =0;i<mysize;i++){
            ListNode* front = q.front();
            q.pop();
            // check for left
            if (front->left && !visited[front->left]){
                q.push(front->left);
                visited[front->left] = true;
                flag = true;
            }
            // check for right
            if (front->right && !visited[front->right]){
                q.push(front->right);
                visited[front->right] = true;
                flag = true;
            }

            // check for parent 
            if (parents[front] && !visited[parents[front]]){
                q.push(parents[front]);
                visited[parents[front]] = true;
                flag = true;
            }
        }
        if (flag == true){
            time++;
        }
    }
    return time;

}
int minTime(ListNode* root,int target){
    // find all nodes parent 
    // find target node addresss pointer

    unordered_map<ListNode*,ListNode*> parents;
    ListNode* add = findparents(root,parents,target);
    
    // cout<<add->data<<endl;
    // start counting time
    return time_to_burn(add,parents);
    

}
int main(){
    ListNode* root = NULL;
    root = buildtree(root);
    print_tree(root);
    cout<<"enter the target from where you want to burn it "<<endl;
    int target;
    cin>>target;
    int ans = minTime(root,target);
    cout<<"total time to burn from target is "<<ans<<endl;

    // 1 2 4 -1 -1 5 7 -1 -1  8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
    // 1 2 4 8 -1 -1 -1 5 10 -1 -1 -1 3 -1 7 -1 -1

}