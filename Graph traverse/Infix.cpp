#include <bits/stdc++.h>
using namespace std;

//string prefixtoinfix(string pre_exp)
//{
//    stack<string> s;
//    int length = pre_exp.size();
//    for (int i = length - 1; i >= 0; i--)
//    {
//
//        if (isOperator(pre_exp[i]))
//        {
//            string op1 = s.top();
//            s.pop();
//            string op2 = s.top();
//            s.pop();
//            string temp = "(" + op1 + pre_exp[i] + op2 + ")";
//            s.push(temp);
//        }
//        else
//        {
//            s.push(string(1, pre_exp[i]));
//        }
//    }
//    return s.top();
//}

string postfixToInfix(string postfix){
    stack<char>s;
    string infix="";
    for(int i=0;i<postfix.size();i++){
        char symbol=postfix[i];
        if((symbol>='0' && symbol<='9')||(symbol>='a' && symbol<='z')||(symbol>='A' && symbol<='Z'))
            s.push(symbol);
        else{
            char a=s.top();
            s.pop();
            char b=s.top();
            s.pop();
            string s="("+a+symbol+b;
            infix+=s+")";
        }
    }
    return infix;
}
int main(){
    string infix,postfix;
    cout<<"Input postfix expression: "<<endl;
    cin>>postfix;

    infix=postfixToInfix(postfix);
    cout<<"infix expression: "<<infix<<endl;
    return 0;
}

