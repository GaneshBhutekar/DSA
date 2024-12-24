#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Node{
    public:
    int data;
    ListNode* left;
    ListNode* right;
    Node(int data){
        ListNode* left = NULL;
        ListNode* right = NULL;
        this->data = data;
    }

};



// create the treee
ListNode* createtree(ListNode* root){
    // creaye the node
    int data;
    cout<<"enter the data"<<endl;
    cin>>data;

    if (data == -1){
        return nullptr;
    }

    root = new Node(data);

    // go for left
    cout<<"left"<<endl;
    root->left = createtree(root->left);

    // then go for right
    cout<<"right"<<endl;
    root->right = createtree(root->right);

    return root;
}


void printtree(ListNode* root){
    // level order
    queue<ListNode*> q;

    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        ListNode* demo = q.front();
        q.pop();
        if (demo==NULL){
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<demo->data<<" ";
            if (demo->left){
                q.push(demo->left);
            }
            if (demo->right){
                q.push(demo->right);
            }
        }
    }
}


void inorder(ListNode* root,vector<int> &arr){

    if (root == NULL){
        return;
    }

    // go for the left
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);

}


vector<int> mergeArray(vector<int> in1,vector<int> in2,int n1,int n2){
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i<n1 && j < n2){
        if (in1[i] <= in2[j]){
            ans.push_back(in1[i]);
            i++;
        }
        else{
            ans.push_back(in2[j]);
            j++;
        }
    }

    // remaining of in1
    while(i<n1){
        ans.push_back(in1[i]);
        i++;
    }
    // remaining of in2
    while(j<n2){
        ans.push_back(in2[j]);
        j++;
    }

    return ans;
}


ListNode* solve(vector<int> merged,int start,int end){
    if (start>end){
        return NULL;
    }

    int mid = (start+end)/2;

    ListNode* root = new Node(merged[mid]);

    // go for the left and then go for the right
    root->left = solve(merged,start,mid-1);
    // go for the right
    root->right = solve(merged, mid+1,end);

    return root;

}
ListNode* mergeTree(ListNode* root1,ListNode* root2){
    // first find the inorder of the tree

    vector<int> in1;
    inorder(root1,in1);
    vector<int> in2; 
    inorder(root2,in2);
    int n1 = in1.size();
    int n2 = in2.size();

    // now merge in into one
    vector<int> merged = mergeArray(in1,in2,n1,n2);

    // now we have merged one also 
    ListNode* root = solve(merged,0,n1+n2-1);
    return root;
}


int main(){
    cout<<"enter the data for root1"<<endl;
    ListNode* root1 = NULL;
    root1 = createtree(root1);

    cout<<"enter for the root2"<<endl;
    ListNode* root2 =nullptr;
    root2= createtree(root2);

    printtree(root1);
    printtree(root2);
    // 6 3 1 -1 -1 4 -1 5 -1 -1 8 7 -1 -1 11 -1 13 -1 -1 18 9 2 -1 6 -1 -1 12 -1 14 -1 -1 19 -1 -1
    // 18 9 2 -1 6 -1 -1 12 -1 14 -1 -1 19 -1 -1

    cout<<"MERGING THIS BOTH TREEE"<<endl;
    ListNode* ans = mergeTree(root1,root2);
    printtree(ans);



}