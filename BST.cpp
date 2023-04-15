#include <bits/stdc++.h>
using namespace std;

//BST//
class node{
public:
    int data;
    node* right;
    node* left;

    node(int d){
        this->data = d;
        right = nullptr;
        left = nullptr;
    }
};

node* insertintobst(node* &root,int d){

    if(root == nullptr){
        root = new node(d);
        return root;
    }

    if(d > root->data){
        root ->right = insertintobst(root->right,d);
    }
    else{
        root ->left = insertintobst(root->left,d);
    }

    return root;
}

void input(node* &root){

    int data;
    cin>>data;

    while(data != -1){
        insertintobst(root,data);
        cin>>data;
    }
}

void lot (node* root){
    if(root == nullptr){
        return;
    }

    queue<node*> q;
    q.push(root);

    q.push(nullptr);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == nullptr){
            cout<<endl;

            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorder(node* root){
    if(root == NULL)
        return;

    //LNR
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node* mini(node* root){
    node* temp = root;

    while(temp != nullptr){
        temp = temp->left;
    }

    return temp;
}

node* maxi(node* root){
    node* temp = root;

    while(temp != nullptr){
        temp = temp->right;
    }

    return temp;
}

node* deletion(node* root,int x){
    if(root == NULL){
        return root;
    }

    if(root->data == x){

        if(root->left == NULL && root->right == NULL){
            delete root;
            return nullptr;
        }

        if(root->left != nullptr && root->right == nullptr){
            node* temp = root->left;
            delete root;
            return temp;
        }

        if(root->left == nullptr && root->right != nullptr){
            node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->left != nullptr && root->right != nullptr){
            //min value replace kregi
            int val = mini(root->left)->data ;
            root->data = val;
            root->left = deletion(root->left,val);
            return root;
        }

    }
    else if(root->data > x){
        root->left = deletion(root->left,x);
        return root;
    }
    else{
        root->right = deletion(root->right,x);
        return root;
    }
}

int main(){

//    node* root = nullptr;
//    cout<<"Enter into bst : "<<endl;
//    input(root);
//
//    int x;
//    cout<<"delete :";
//    cin>>x;
//    deletion(root,x);
//
//    cout<<"Your bst : "<<endl;
//    lot(root);

    vector<int> v {1,3,4,5,6,7};

    auto it = find(v.begin(),v.end(),4);

    int index = it - v.begin();

    cout<<index;

    return 0;
}