#include<bits/stdc++.h>
using namespace std;
#define INF 1e5
/*
6
10
5
1
10
2
10
A15 = ((A1*A2)*((A3*A4)*A5))
*/
void Print_Optimal_Parens(vector<vector<int>> &s, int i, int j)
{
    if(i==j)
        cout<<"A"<<i;
    else{
        cout<<"(";
        Print_Optimal_Parens(s,i,s[i][j]);
        cout<<"*";
        Print_Optimal_Parens(s,s[i][j]+1,j);
        cout<<")";
    }
}

void Matrix_Chain_Order(vector<int> p)
{
    int n=p.size()-1;
    vector<vector<int>> m(n+1, vector<int> (n+1));
    vector<vector<int>> s(n+1, vector<int> (n+1));
    for(int i=1; i<=n; i++)
        m[i][i]=0;
    for(int l=2; l<=n; l++){
        for(int i=1; i<=n-l+1; i++){
            int j=i+l-1;
            m[i][j]=INF;
            for(int k=i; k<=j-1; k++){
                int q=m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    cout<<"A1"<<n<<" = ";
    Print_Optimal_Parens(s,1,n);
}

int main()
{
    int n;
    cout<<"Length of chain: ";
    cin>>n;
    vector<int> p;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        p.push_back(x);
    }
    Matrix_Chain_Order(p);
    return 0;
}
