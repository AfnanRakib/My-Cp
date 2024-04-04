#include <bits/stdc++.h>
using namespace std;

void TOH(int n,int a,int b,int c){
    if(n>0){
        TOH((n-1),a,c,b);
        cout<<n<<": "<<a<<" -> "<<c<<endl;
        TOH((n-1),b,a,c);
    }
}

int main(){
    int n;
    cin>>n;
    TOH(n,1,2,3);
    return 0;
}
