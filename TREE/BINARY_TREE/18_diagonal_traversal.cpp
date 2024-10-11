#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this ->data = data;
        this -> left = NULL;
        this -> right = NULL;

    }
};


Node* buildtree(Node* &root){
    int data;
    cout<<"enter the data"<<endl;
    cin>>data;
    if (data == -1){
        return NULL;
    }
    root = new Node( data);
    cout<<"for left"<<endl;
    root->left = buildtree(root->left);
    cout<<"for right"<<endl;
    root->right = buildtree(root->right);
    return root;

}
void print_array(vector<int> arr){
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
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

vector<int> diagonal_traversal(Node* root){

    // don't know why this gicing wring output
    // ans to store the values.
    vector<int> ans;
    // data structure to store during the level order traversal.
    map<int,vector<int>> store;
    // data structire of queue to traverse in level order.
    queue<pair<Node* , pair<int,int>>> q;

    // start from here.
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p = q.front();
        q.pop();

        // insert data into the store.
        int data = p.first->data;
        int x = p.second.first;
        int y = p.second.second;
        int index = x-y;

        store[index].push_back(data);

        if (p.first->left != NULL){
            q.push({p.first->left,{x-1,y+1}});
        }
        if (p.first->right != NULL){
            q.push({p.first->right,{x+1,y+1}});
        }

    }
    // push all the element to the ans.
    for(auto i = store.rbegin(); i!= store.rend();i++){
        for(auto j:(*i).second){
            ans.push_back(j);
        }
    }

    return ans;
}



vector<int> diagonal_traversal_2(Node* root){
    vector<int> ans;
    if (root == NULL) return ans;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* demo = q.front();
        q.pop();    
        while(demo!= NULL){
            if (demo->left != NULL ){
                q.push(demo->left);
            }
            ans.push_back(demo->data);
            demo= demo->right;
        }
    }
    return ans;

}

int main(){
    // 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
    // 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 11 -1 -1 5 2 -1 -1 -1 
    Node* root=NULL;
    buildtree(root);
    print_tree(root);
    vector<int> ans = diagonal_traversal_2(root);
    print_array(ans);

}