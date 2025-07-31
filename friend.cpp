#include<iostream>
using namespace std;
void findmax(); // friend prototype
class number1{
    int num1;
    public:
        number1(){
            cout << "Enter Value of Num1" << endl;
            cin >> num1;
        }
        friend void findmax(); 
};
class number2{
    int num2;
    public:
        number2(){
            cout << "Enter Value of Num2" << endl;
            cin >> num2;
        }
        friend void findmax(); 
};
void findmax(){
    number1 n1;
    number2 n2;
    if(n1.num1>n2.num2){
        cout << "Num1 is geater" << endl;
    }
    else{
        cout << "Num2 is geater" << endl;

}
}
int main(){
    findmax();
    return 0;
}