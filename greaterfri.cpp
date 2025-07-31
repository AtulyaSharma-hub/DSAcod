#include<iostream>
using namespace std;
class B;// prototype B declared
class A{
    int numa;// private datatypr
    public:
        A(int a){ // A  class constructor
            numa=a;
        }
        friend void findgreater(A,B);};
class B{
    int numb;// private datatypr
    public:
        B(int b){ // B class constructor
            numb=b;
        }
        friend void findgreater(A,B);};
void findgreater (A obja,B objb){
    cout << "Greater element is : " << (obja.numa > objb.numb ? obja.numa : objb.numb);}
int main(){
    A obja(10); B objb(20);
    findgreater(obja,objb);
    return 0;
}