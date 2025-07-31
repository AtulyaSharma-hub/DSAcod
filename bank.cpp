#include<iostream>
using namespace std;
class bank{
    int acc_no,balance;
    string name;
   public:
    bank(){
        acc_no=0;
        name="";
        balance=0;
        }
    bank(int x,int y,string z){
        acc_no=x;
        balance=y;
        name=z;
    }  
    void deposit(int amount){
        balance+=amount;
    }  
    void withdraw(int amount){
        balance-=amount;
        if(balance<0){ cout<<"money limit exceeded:\n";
        exit(0);
        }
    }
    
    void display(){
        cout<<"Account Number: "<<acc_no<<endl;
        cout<<"Account Holder Name: "<<name<<endl;
        cout<<"Balance :"<<balance<<endl;
    }
};
int main(){
    bank b1,b2(123,1000,"Rahul");
    b1.deposit(500);
    b1.display();
    b2.withdraw(100);
    b2.display();
}