#include<iostream>
#include<cmath>
using namespace std;
void display(int arr[],int n){
    int max=arr[0],min=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max) max=arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i]<min) min=arr[i];
    }
    cout<<"Maximum :\n"<<max<<endl;
    cout<<"Minimum :\n"<<min<<endl;
}
int main(){
    int n;
    cout<<"Enter Array Size:\n";
    cin>>n;
    int a[n];
    cout<<"Enter Elements:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    display(a,n);
}