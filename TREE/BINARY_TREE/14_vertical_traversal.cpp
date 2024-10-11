#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this ->data = data;
        this ->left = NULL;
        this ->right = NULL;
    }
};

Node* buildtree(Node* &root){
    int data;
    cout<<"enter the data "<<endl;
    cin>> data;
    if (data == -1){
        return NULL;
    }

    root = new Node(data);
    cout<<"for left"<<endl;
    root->left = buildtree(root->left);
    cout<<"for right"<<endl;
    root->right = buildtree(root->right);

    return root;
}

void print_tree(Node* root){
    if (root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
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
vector<int> vertical_traversal(Node* root){

    vector<int> ans;

    // whee to stire the data.
    map<int,map<int,vector<int>>> store;
    // queue to stire the node , vertical and level wise index.
    queue<pair<Node*,pair<int,int>>> q;
    // here it is pair of nodes and index 
    //push first value
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p = q.front();
        q.pop();

        // push this is in store
        // data
        int data = p.first->data;
        // vertical index
        int x = p.second.first;
        // level index
        int y = p.second.second;

        // push it intp store varible
        store[x][y].push_back(data);

        // add left amd right in queue.
        if (p.first->left != NULL){
            q.push({p.first->left,{x-1,y+1}});
        }
        if (p.first->right != NULL){
            q.push({p.first->right,{x+1,y+1}});
        }

    }

    // now store has the data we have to push it into the ans
    for(auto i:store){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }

    return ans;
}



int main(){
    // 1 2 4 -1 8 10 -1 -1 -1 5 -1 -1 3 7 -1 -1 6 -1 9 -1 -1 
    Node* root = NULL;
    buildtree(root);
    print_tree(root);

    vector<int> ans = vertical_traversal(root);
    for(int i : ans){
        cout<<i<<" ";

    }
    cout<<endl;

}