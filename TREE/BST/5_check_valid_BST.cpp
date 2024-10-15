    #include<iostream>
    #include<vector>
    #include<queue>
    using namespace std;


    class Node{
        public:
        int data;
        Node* right;
        Node* left;
        Node(int data){
            this->data = data;
            this->right = NULL;
            this->left = NULL;
        }
    };


    // input in the binary search tree
    Node* insertBST(Node* &root,int data){
        if(root == NULL){
            // we came where to put the data.
            root = new Node(data);
            return root;
        }

        // traverse their 
        if (root->data > data){
            root ->left = insertBST(root->left,data);
        }
        else{
            root->right = insertBST(root->right,data);
        }
        return root;


    }


    void print_tree(Node* root){
        if (root ==NULL){
            return;
        }
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* demo = q.front();
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
                if (demo ->right){
                    q.push(demo->right);
                }
            }
        }

    }

void insertingdata(Node* &root){
    int data;
    cout<<"enter the data (-1 for exit)"<<endl;
    cin>>data;
    while(data != -1){
        insertBST(root,data);
        cin>>data;
    }
}


bool solve(Node* root,pair<int,int> range){

    if (root == NULL){
        return true;
    }

    if (root->data <= range.first || root->data >= range.second){
        return false;
    }

    // traverse to left
    int left = solve(root->left,{range.first,root->data});
    int right = solve(root->right,{root->data,range.second});
    return left & right;

}
// now check that it is valid or not
bool checkBST(Node* root){
    pair<int,int> range = {INT_MIN,INT_MAX};
    return solve(root,range);
    
}


// get normal tree
Node* insertBT(Node* &root,vector<int> data,int &index){
    int num = data[index];
    index++;
    if (num == -1){
        return NULL;
    }

    root = new Node(num);

    root->left = insertBT(root->left,data,index);
    root->right = insertBT(root->right,data,index);
    return root;

}



//check by inorder way
bool inorderWay(Node* root,int &prev){
    if (root == NULL){

        return true;
    }

    // got left all the way 
    bool left = inorderWay(root->left,prev);

    //  after reaching to the left check that the left is sorted or not
    if (root->data <= prev){
        return false;
    }

    prev = root->data;

    bool right = inorderWay(root->right,prev);
    return left & right;
}

int main(){
    Node* root = NULL;
    insertingdata(root);
    print_tree(root);

    // 10 16 2 4 11 13 48 3
    if (checkBST(root)){
        cout<<"it is valid BST"<<endl;
    }
    else{
        cout<<"it is not"<<endl;
    }

    vector<int> data = {10,5,3,-1,-1,4,-1,-1,16,11,-1,-1,17,-1,19,-1,-1};
    // 10,5,3,-1,-1,4,-1,-1,16,11,-1,-1,17,-1,19,20,-1,-1,-1
    Node* root1= NULL;
    int index = 0;
    insertBT(root1,data,index);
    print_tree(root1);
    if (checkBST(root1)){
        cout<<"yes it is also"<<endl;
    }
    else{
        cout<<"no it is not"<<endl;
    }


    // chec through inorder 
    int prev = INT_MIN;
    cout<<inorderWay(root1,prev)<<endl;


}