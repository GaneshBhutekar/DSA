#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;


class Node  {
    public:
    int data;
    ListNode* right;
    ListNode* left;
    Node(int data){
        this ->data = data;
        left = NULL;
        right = NULL;

    }
};

ListNode* createtree(ListNode* root){
    int data;
    cout<<"enter the data"<<endl;

    cin>>data;
    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout<<"for left"<<endl;
    root->left = createtree(root->left);

    cout<<"for right "<<endl;
    root->right = createtree(root->right);

    return root;
}


void printtree(ListNode* root){
    if (root == NULL) return;
    queue<ListNode*> q;

    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        ListNode* demo = q.front();

        q.pop();
        if (demo == NULL){
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



// creating the tree using preorder and inorder 
// where inorder is use to check that node left have any node not if yes then we move more if not then just go back
// we use preorder to traverse because that's how we create the tree

ListNode* solve(int &index,int pre[],int in[],int pre_start,int pre_end,int n,map<int,int> mp){


    if (index >= n || pre_start > pre_end){
        return NULL;
    }

    // data nikalo
    int element = pre[index++];
    // jo pre ka data hain use node banao
    ListNode* root = new Node(element);

    // find the position of this element in the pre array
    // int position = mp[element];
    // go for left
    root->left = solve(index,pre,in,pre_start,mp[element] -1,n,mp);

    // go for the right 
    root->right = solve(index,pre,in,mp[element]+1,pre_end,n,mp);

    return root;
}


ListNode* buildtree(int in[], int pre[],int n){
    map<int,int> mp;
    for(int i =0;i<n;i++){
        mp[in[i]] = i;
    }

    return solve(0,pre,in,0,n-1,n,mp);
}

int main(){
    // ListNode* root = NULL;

    // root = createtree(root);
    
    // 0 1 3 -1 -1 4 -1 -1 2 5 -1 -1 -1
    int in[] = {3,1,4,0,5,2};
    int pre[] = {0,1,3,4,2,5};
    int n = 6;

    ListNode* root = buildtree(in,pre,6);
    printtree(root);
}