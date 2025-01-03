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
        this->right = NULL;
        this->left = NULL;
        this ->data = data;
    }
};



void insertData(ListNode* &root,int data){
    if (root == NULL){
        root = new Node(data);
        return;
    }

    ListNode* temp = root;
    while(true){
        if (temp->data > data){
            if (temp->left){
                temp = temp->left;                                
            }

            else{
                ListNode* newone = new Node(data);
                temp->left = newone;
                break;
            }
        }

        else{
            if (temp->right){
                temp = temp->right;
            }
            else{
                ListNode* newone = new Node(data);
                temp->right =  newone;
                break;
            }
        }
    }

}


ListNode* insertRecursive(ListNode* root , int data){
    if (root == NULL){
        root = new Node(data);
        return root;
        // this will return the node which created to the prev node
    }

    if (root ->data > data){
        // go to left because you are small
        root->left = insertRecursive(root->left,data);

    }
    else{
        root ->right = insertRecursive(root->right,data);
    }

    return root;
}


void  createBST(ListNode* &root){
    cout<<"enter the data"<<endl;
    int data;
    cin>> data;
    while(data != -1){
        root = insertRecursive(root,data);
        cout<<"insert the data"<<endl;
        cin>>data;
    }

    
}
void  print_tree(ListNode* root){
    // level order traversal
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
            cout<<demo ->data<<" ";
            if (demo->left){
                q.push(demo->left);
            }
            if (demo->right){
                q.push(demo->right);
            }
        }
    }

}



bool searchBST(ListNode* root,int data){
    // search that element is in tree or not
    if (root == NULL){
        return false;
    }

    if (root ->data == data){
        return true;
    }

    bool ans;
    if (root -> data > data){
        return  searchBST(root->left,data);
    }
    else{
        return searchBST(root->right,data);
    }

}

bool searchbyloop(ListNode* root, int data){
    if(root == NULL){
        return false;
    }

    while(root != NULL){
        if (root ->data == data){
            return true;
        }

        else if (root->data > data){
            root = root ->left;
        }
        else{
            root = root->right;
        }
    }

    return false;
}
int main(){

    ListNode* root  = NULL;
    // vector<int> input = {10,6,4,18,13,11,3,7};
    // for(int i:input){
    //     insertData(root,i);
    // }

    createBST(root);
    print_tree(root);
    int data;
    cout<<"enter the data to find"<<endl;
    cin >> data;
    if (searchbyloop(root,data)){
        cout<<"yes it is present"<<endl;
    }
    else{
        cout<<"no it is not present"<<endl;
    }
    // 10 6 4 18 13 11 3 7 -1

}