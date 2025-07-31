#include<iostream>
using namespace std;
class node{
    int data,height;
    node* left;
    node* right;
    public:
        node(int val){
            data = val;
            height = 1;
            left = right = nullptr;
        }
    int getheight(node* n){
        return n->height;
    } 
    int getbal(node* n){
        return getheight(n->left) - getheight(n->right); 
    }
    node* rotleft(node* x){
        node* y = x->right;
        node* t2 = y->left;
        y->left = x;
        x->right = t2;
        x->height = 1 + max(getheight(x->left),getheight(x->right));
        y->height = 1 + max(getheight(y->left),getheight(y->right));
        return y;
    } 
    node* rotright(node* y){
        node* x = y->left;
        node* t2 = x->right;
        x->right = y;
        y->left = t2;
        x->height = 1 + max(getheight(x->left),getheight(x->right));
        y->height = 1 + max(getheight(y->left),getheight(y->right));
        return x;
    } 
    node* insert(node* root,int key){
        if(!root) return new node(key);
        if(key<root->data) root->left = insert(root->left,key);
        if(key>root->data) root->right = insert(root->right,key);
        return root;
        root->height = 1 +max(getheight(root->left),getheight(root->right));
        int bal = getbal(root); 
    
        
    // balance cases
    if(bal>1 && key< root->left->data) return rotright(root);
    if(bal>1 && key > root->left->data) {
        root->left = rotleft(root->left);
        return rotright(root);
    }
    if(bal<-1 && key>root->right->data) return rotleft(root);
    if(bal<-1 && key<root->right->data ){
        root->right = rotright(root->right);
        return rotleft(root);
    }
    }
    void preorder(node *root){
        if(root == NULL) return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    node* search(node *root,int val){
        if(root==nullptr || root->data==val){
            return root;
        }
        if(val<root->data){
            return search(root->left,val);
        }else{
            return search(root->right,val);
        }
    }
    node* deleteNode(node *root,int val){
        if(root==nullptr){
            return root;
        }
        if(root->left==nullptr && root->right==nullptr){
            delete root;
            return nullptr;
        }
        if(val<root->data){
            root->left=deleteNode(root->left,val);
        }else if(val>root->data){
            root->right=deleteNode(root->right,val);
        }else{
            if(root->left==nullptr){
                node *temp=root->right;
                delete root;
                return temp;
            }else if(root->right==nullptr){
                node *temp=root->left;
                delete root;
                return temp;
            }
            node *temp=root->right;
            while(temp && temp->left!=nullptr){
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
        return root;
    }
    void inorder(node* root){
        if(root==nullptr){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);  
    }
};
int main(){
    node *n1 = nullptr;
    n1 = n1->insert(n1,23);
    n1->insert(n1,43);
    n1->insert(n1,12);
    n1->insert(n1,45);
    n1->insert(n1,67);
    n1->insert(n1,89);
    n1->insert(n1,90);
    n1->insert(n1,100);
    n1->insert(n1,110);
    n1->insert(n1,120);
    n1->insert(n1,130);
    n1->insert(n1,140);
    n1->preorder(n1);
    return 0;
}