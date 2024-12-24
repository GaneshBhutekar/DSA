#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    ListNode* left;
    ListNode* right;
    Node(int data){
        this->data = data;
        this->right = NULL;
        this ->left = NULL;
    }
};

ListNode* buildtree(ListNode*& root){
    int data;
    cout<<"enter the element: "<<endl;
    cin>>data; 
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

void print_array(vector<int> arr){
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}


void print_tree(ListNode* root){
    if (root == NULL){
        return;
    }

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


vector<int> right_view(ListNode* root){
    vector<int> ans;
    if (root == NULL){
        return ans;
    }

    // to store.
    map<int,int> store ;
    // to queue
    queue<pair<ListNode*,int>> q;

    //push first element.
    q.push({root,0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();

        // push the element.
        int index = p.second;
        int data = p.first->data;
        store[index] = data;

        // add next right and left
        if (p.first->left){
            q.push({p.first->left,index+1});
        }
        if (p.first->right){
            q.push({p.first->right,index+1});
        }
    }
    for(auto i:store){
        ans.push_back(i.second);
    }
    return ans;
}

// toptimized version of right view.
void right_view_2(ListNode* root,vector<int> & ans , int level){
    if (root == NULL){
        return;
    }

    if (ans.size() == level){
        ans.push_back(root->data);
    }


    // go for right first 
    right_view_2(root->right,ans,level+1);
    // then go for right
    right_view_2(root->left,ans,level+1);


}

vector<int> for_right(ListNode* root){
    vector<int> ans ;
    int level = 0;
    right_view_2(root,ans,0);
    return ans;
}



void solve(ListNode* root,vector<int> &ans,int level){
    if (root == NULL){
        return;
    }

    if (level == ans.size()){
        // cout<<"level "<<level<<endl;
        ans.push_back(root->data);
    }

    // now the size is 1 but level is 0

    solve(root->left,ans,level+1);
    // now the level is 1 and size is also 1. when it again come to this level it is already.

    solve(root->right,ans,level+1);
}

vector<int> left_view(ListNode* root){
    vector<int> ans;
    if (root == NULL){
        return ans;
    }
    solve(root,ans,0);
    return ans;
    
}
int main(){
    // 1 2 4 -1 8 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    // 1 2 4 -1 8 -1 -1 5 -1 -1 3 6 -1 -1 7 9 -1 10 -1 -1 16 -1 11 -1 -1 
    ListNode* root = NULL;
    buildtree(root);
    print_tree(root);

    cout<<"roght view and left view"<<endl;
    vector<int> right_ans = right_view(root);

    // optimized way.
    right_ans = for_right(root);
    print_array(right_ans);
    vector<int> for_left = left_view(root);
    print_array(for_left);

    

}