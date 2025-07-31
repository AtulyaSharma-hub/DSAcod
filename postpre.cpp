#include <iostream>
#include <stack>
using namespace std;
int evaluate(string exp){
    stack<int> s;
    for(char ch : exp){
        if(isdigit(ch)){   
            s.push(ch - '0');// Convert char to int
        }
        else{
            int val2 = s.top(); s.pop();//pop1
            int val1 = s.top(); s.pop();//pop2
            switch(ch){
                case '+': s.push(val1 + val2); break; //pop2 + pop1
                case '-': s.push(val1 - val2); break; //pop2 - pop1
                case '*': s.push(val1 * val2); break; //pop2 * pop1
                case '/': s.push(val1 / val2); break; //pop2 / pop1
            }
        }
    }
    return s.top();
}
int prefixEvaluate(string exp){
    stack<int> s;
    for(int i = exp.length() - 1; i >= 0; i--){
        char ch = exp[i];
        if(isdigit(ch)){
            s.push(ch - '0');
        }
        else{
            int val1 = s.top(); s.pop();//pop1
            int val2 = s.top(); s.pop();//pop2
            switch(ch){
                case '+': s.push(val1 + val2); break;//pop1 + pop2
                case '-': s.push(val1 - val2); break;//pop1 - pop2
                case '*': s.push(val1 * val2); break;//pop1 * pop2
                case '/': s.push(val1 / val2); break;//pop1 / pop2
            }
        }
    }
    return s.top();
}
int main(){
    string exp = "23*54+23*+12-";
    cout << "Postfix Expression: " << exp << endl;
    cout << "Result: " << evaluate(exp) << endl;
    cout << "Evaluation Complete." << endl;
    string exp2 =  "-+*23*54+12";
    cout << "Prefix Expression: " << exp2 << endl;
    cout << "Result: " << prefixEvaluate(exp2) << endl;

    return 0;
}