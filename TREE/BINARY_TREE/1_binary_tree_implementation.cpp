    // create the binary tree and traverse it through reverse or normally also.
    #include<iostream>
    #include<stack>
    #include<queue>
    using namespace std;

    // class to create the tree node
    class node{
        public:
        int data;
        ListNode* left;
        ListNode* right;
        node(int data){
            this -> data = data;
            this->left = NULL;
            this-> right = NULL;

        }
    };



    // create the binary tree.
    ListNode* createtree(ListNode* &root){
        // get data
        cout<<"enter the data"<<endl;
        int data;
        cin>> data;
        if (data == -1){
            return NULL;
        }
        root = new node(data);


        // for the left.
        cout<<"For left "<<endl;
        root->left = createtree(root->left);
        // for the right.
        cout<<"for right "<<endl;
        root -> right = createtree(root->right);
        return root;
    }

    void normal_traversal(ListNode*root){
        // we need queue for it.
        queue<ListNode*> q;
        // add first element in it.
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            ListNode* demo = q.front();
            q.pop();
            if(demo == NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                cout<<demo->data<<" ";
                if (demo-> left != NULL){
                    q.push(demo->left);
                }
                if (demo->right != NULL){
                    q.push(demo->right);
                }            

            }

        }
    }


    void reverse_traversal(node * root){
        // here we use stack for this by inputing the alll queue inside of it
        queue<ListNode*> q;
        stack<ListNode*> st;
        q.push(root);
        q.push(NULL);
        st.push(root);
        st.push(NULL);
        while(!q.empty()){
            // store the first node of queue.
            ListNode*demo = q.front();
            q.pop();
            if (demo == NULL){
                cout<<endl;
                if (!q.empty()){
                    q.push(NULL);
                    st.push(NULL);
                }
            }
            else{
                if (demo->left != NULL){
                    q.push(demo->left);
                    st.push(demo->left);
                }
                if (demo ->right != NULL){
                    q.push(demo->right);
                    st.push(demo->right);
                }
            }
        }

        // print in reverse.
        while(st.top()  == NULL){
            st.pop();
        }
        while(!st.empty()){
            if (st.top() == NULL){
                cout<<endl;
            }
            else{
                cout<<st.top()->data<<" ";
            }
            st.pop();

        }
    }

    int main(){
        ListNode* root = NULL;
        createtree(root);
        cout<<"normal traversal"<<endl;
        normal_traversal(root);

        reverse_traversal(root);




    }