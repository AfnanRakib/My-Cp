/*
    MD.RAKIB HASAN
    20210204027

    infix: ((3+4)*2)/7
    Postfix: 34+2*7/
    Value: 2
*/


#include <bits/stdc++.h>
using namespace std;

int precedence(char c){
    if(c=='^') return 5;
    else if(c=='*'||c=='/') return 4;
    else if(c=='+'||c=='-') return 3;
    else return -1;
}

string infixToPostfix(string infix){
    stack<char>s;
    string postfix="";
    for(int i=0;i<infix.size();i++){
        char symbol=infix[i];
        if((symbol>='0' && symbol<='9')||(symbol>='a' && symbol<='z')||(symbol>='A' && symbol<='Z'))
            postfix=postfix+symbol;
        else if(symbol=='(')
            s.push(symbol);
        else if(symbol==')'){
            while(!s.empty() && s.top()!='(')
            {
                postfix=postfix+s.top();
                s.pop();
            }
            if(!s.empty())
                s.pop();
        }
        else if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='^'){
            while(!s.empty() && precedence(symbol)<=precedence(s.top()))
            {
                postfix=postfix+s.top();
                s.pop();
            }
            s.push(symbol);
        }
    }
    while(!s.empty()){
        postfix=postfix+s.top();
        s.pop();
    }
    return postfix;
}

string evalutePostfix(string postfix){
    stack<char>s;
    for(int i=0; i< postfix.size(); i++)
    {
        char symbol=postfix[i];
        if(symbol == ' ')
            continue;
        else if((symbol>='a' && symbol<='z')||(symbol>='A' && symbol<='Z'))
            return "Can evaluate numbers only";
        else if(symbol>='0' && symbol<='9')
            s.push(symbol-'0');
        else{
            if(s.empty())
                return "Not enough operands";
            int a=s.top();
            s.pop();
            if(s.empty())
                return "Not enough operands";
            int b=s.top();
            s.pop();
            switch(symbol){
            case'^':
                s.push(pow(b,a));
                break;
            case '*':
                s.push(b*a);
                break;
            case '/':
                s.push(b/a);
                break;
            case '+':
                s.push(b+a);
                break;
            case '-':
                s.push(b-a);
                break;
            }
        }
    }
    string value=to_string(s.top());
    s.pop();
    if(s.empty())
        return value;
    else
        return "Not enough operators";
}


int main(){
    string infix,postfix;
    cout<<"Input infix expression: "<<endl;
    cin>>infix;

    postfix=infixToPostfix(infix);
    cout<<"Postfix expression: "<<postfix<<endl;
    cout<<"Value: "<<evalutePostfix(postfix)<<endl;
    return 0;
}
