#include<iostream>
//#include<string>
using namespace std;
void reverse(string &str){
    
    int n=str.length();
    string a(n,' ');//initalize a string of n length with space
    for(int i=0;str[i]!='\0';i++){
        a[i]=str[n-i-1];
    }
    cout<<"Reverse of string is:\n";
    cout<<a;
}
int main(){
  string s1;
  cout<<"Enter a String:\n";
  cin>>s1;
    reverse(s1);
}