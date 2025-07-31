#include<iostream>
#define size 500
using namespace std;
class stack{
    int top;
    int arr[size];
    public:
        stack(){
            top = -1;
        }
        void push(int x){
            if(top>=size-1){
                
                cout << "Stack Overflow" << endl;
                return;
            }
            arr[++top] = x;
        }
        int pop(){
            if(top<0){
                cout << "Stack Underflow" << endl;
                return 0;
            }
            return arr[top--];
        }
        int peek(){
            if(top<0){
                cout << "Stack is empty" << endl;
                return 0;
            }
            return arr[top];
        }
        void display(){
            if(top<0){
                
                cout << "Stack is empty" << endl;
                return;
            }
            for(int i=top;i>=0;i--){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};
class node{
    int data;
    node* left,*right;
    public:
        node(int val){
            data = val;
            left = right = NULL;
        }
        void preorder(node* root){
            if(root == NULL)
                return;
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
        node* insert(node* root,int val){
            if(root == NULL){
                return new node(val);
            }
            if(val < root->data){
                root->left = insert(root->left,val);
            }else{
                root->right = insert(root->right,val);
            }
            return root;
        }
        node * search(node* root,int val){
            if(root == NULL || root->data == val)
                return root;
            if(val < root->data)
                return search(root->left,val);
            return search(root->right,val);
        }
        node *rightRotate(node* root){
            node* x = root->left;
            node* y = x->right;
            x->right = root;
            root->left = y;
            return x;
        }
        node *leftRotate(node* root){
            node* x = root->right;
            node* y = x->left;
            x->left = root;
            root->right = y;
            return x;
        }
};
class queue{
    int arr[size];
    int front,rear;
    public:
        queue(){
            front = rear = -1;
        }
        void enqueue(int x){
            if(rear>=size-1){
                
                cout << "Queue Overflow" << endl;
                return;
            }
            if(front == -1) front = 0;
            arr[++rear] = x;
        }
        int dequeue(){
            if(front==-1 || front>rear){
                
                cout << "Queue Underflow" << endl;
                return 0;
            }
            return arr[front++];
        }
        void display(){
            if(front == -1){
                
                cout << "Queue is empty" << endl;
                return;
            }
            for(int i=front;i<=rear;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};
void merge(int arr[],int l,int m,int r){
    int n1 = l-m+1;
    int n2 = r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n2;i++) R[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int partition(int arr[],int l,int r){
    int pivot = arr[r];
    int i = l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }    
    swap(arr[i+1], arr[r]);
    return i+1;
}
void quicksort(int arr[],int l,int r){
    if(l<r){
        int pi = partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
}