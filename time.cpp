#include<iostream>
#include<cstdlib>
using namespace std;
class time{
    int hours;
    int min;
    int sec;
    public:
    time(){
        hours=0;
        min=0;
        sec=0;
    }
    time(int hours,int min,int sec){
        this->hours=hours;
        this->min=min;
        this->sec=sec;
    }
        void display();
        time operator +(time &obj){
            time sum;
            sum.hours=hours+obj.hours;
            sum.min=min+obj.min;
            sum.sec=sec+obj.sec;
            return sum;
        }
    
};
void time::display(){
    cout<<hours<<":"<<min<<":"<<sec<<endl;
}
int main(){
    time t1(2,23,12),t2(2,30,0);
    cout<<"Time t1:\n";
    t1.display();
    cout<<"Time t2:\n";
    t2.display();
    time t3;
    t3=t1+t2;
    cout<<"Sum :\n";
    t3.display();
}