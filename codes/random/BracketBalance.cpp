#include <bits/stdc++.h>
using namespace std;
/*
Md.Rakib Hasan
ID: 20210204027

test :
[{()}]  Valid
[{()}   Invalid
[}()]{  Invalid
*/

bool valid(string s){
    int n=s.size();
    stack<char> st;
    bool f=true;
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
        else if(!st.empty() && s[i]==')'){
            if(st.top()=='(')
                st.pop();
            else{
                f=false;
                break;
            }
        }
        else if(!st.empty() && s[i]=='}'){
            if(st.top()=='{')
                st.pop();
            else{
                f=false;
                break;
            }
        }
        else if(!st.empty() && s[i]==']'){
            if(st.top()=='[')
                st.pop();
            else{
                f=false;
                break;
            }
        }
    }
    if(!st.empty())
        f=false;
    return f;
}

int main(){
    string s;
    cin>>s;

    if(valid(s))
        cout<<"Valid"<<endl;
    else
        cout<<"Invalid"<<endl;
    return 0;
}
